/**
 * @file montiro.cpp
 * @author ymy1248
 * @brief 
 * @version 0.1
 * @date 2021-01-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "monitor.hpp"

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#include <sys/resource.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <mach/mach_port.h>
#include <mach/mach_traps.h>
#include <mach/task_info.h>
#include <mach/thread_info.h>
#include <mach/thread_act.h>
#include <mach/vm_region.h>
#include <mach/vm_map.h>
#include <mach/task.h>
#include <mach/shared_memory_server.h>

#include <chrono>

namespace ymy {



#ifdef __APPLE__
/* On Mac OS X, the only way to get enough information is to become root. Pretty frustrating!*/
int Monitor::getProcInfo(pid_t pid, ProcInfo &info) {
    task_t task;
    kern_return_t error;
    mach_msg_type_number_t count;
    thread_array_t thread_table;
    thread_basic_info_t thi;
    thread_basic_info_data_t thi_data;
    unsigned table_size;
    struct task_basic_info ti;

    error = task_for_pid(mach_task_self(), pid, &task);
    if (error != KERN_SUCCESS) {
        /* fprintf(stderr, "++ Probably you have to set suid or become root.\n"); */
        info.rss = info.vsize = 0;
        info.utime = info.stime = 0;
        return 0;
    }
    count = TASK_BASIC_INFO_COUNT;
    error = task_info(task, TASK_BASIC_INFO, (task_info_t)&ti, &count);
    assert(error == KERN_SUCCESS);
    { /* adapted from ps/tasks.c */
        vm_region_basic_info_data_64_t b_info;
        vm_address_t address = GLOBAL_SHARED_TEXT_SEGMENT;
        vm_size_t size;
        mach_port_t object_name;
        count = VM_REGION_BASIC_INFO_COUNT_64;
        error = vm_region_64(task, &address, &size, VM_REGION_BASIC_INFO,
                             (vm_region_info_t)&b_info, &count, &object_name);
        if (error == KERN_SUCCESS) {
            if (b_info.reserved && size == (SHARED_TEXT_REGION_SIZE) &&
                ti.virtual_size > (SHARED_TEXT_REGION_SIZE + SHARED_DATA_REGION_SIZE)) {
                ti.virtual_size -= (SHARED_TEXT_REGION_SIZE + SHARED_DATA_REGION_SIZE);
            }
        }
        info.rss = ti.resident_size;
        info.vsize = ti.virtual_size;
    }
    { /* calculate CPU times, adapted from top/libtop.c */
        unsigned i;
        info.utime = ti.user_time.seconds + ti.user_time.microseconds * 1e-6;
        info.stime = ti.system_time.seconds + ti.system_time.microseconds * 1e-6;
        error = task_threads(task, &thread_table, &table_size);
        assert(error == KERN_SUCCESS);
        thi = &thi_data;
        for (i = 0; i != table_size; ++i) {
            count = THREAD_BASIC_INFO_COUNT;
            error = thread_info(thread_table[i], THREAD_BASIC_INFO, (thread_info_t)thi, &count);
            assert(error == KERN_SUCCESS);
            if ((thi->flags & TH_FLAGS_IDLE) == 0) {
                info.utime += thi->user_time.seconds + thi->user_time.microseconds * 1e-6;
                info.stime += thi->system_time.seconds + thi->system_time.microseconds * 1e-6;
            }
            if (task != mach_task_self()) {
                error = mach_port_deallocate(mach_task_self(), thread_table[i]);
                assert(error == KERN_SUCCESS);
            }
        }
        error = vm_deallocate(mach_task_self(), (vm_offset_t)thread_table,
                              table_size * sizeof(thread_array_t));
        assert(error == KERN_SUCCESS);
    }
    mach_port_deallocate(mach_task_self(), task);
    return 0;
}
#endif


Monitor::Monitor(MonitorType type)
: type_(type),
  pid_(getpid()) {
    if (isTypeChecked(MonitorType::ELAPSED_TIM)) {
        start_ = std::chrono::high_resolution_clock::now();
    }
    ProcInfo info;
    if (!getProcInfo(pid_, info)) {
        rss_ = info.rss;
        vsize_ = info.vsize;
        utime_ = info.utime;
        stime_ = info.stime;
        std::cout << "Successfully built monitor!" << std::endl
                  << "Rss: " << rss_ << std::endl;
    } else {
        std::cout << "Error: Can't get system info." << std::endl;
        assert(false);
    }

    rusage usage;
    assert(!getrusage(RUSAGE_SELF, &usage));
    std::cout << "USAGE RSS: " << usage.ru_idrss << std::endl;
}

Monitor::~Monitor() {
    ProcInfo info;
    if (!getProcInfo(pid_, info)) {
        int64_t delta_rss = info.rss - rss_;
        int64_t delta_vsize = info.vsize - vsize_;
        double delta_utime = info.utime - utime_;
        double delta_stime = info.stime - stime_;
        auto finish = std::chrono::high_resolution_clock::now();

        std::cout << "Current Rss: "
                  << info.rss << std::endl;

        std::cout << "Elapsed time: "
                  << std::chrono::duration_cast<milli>(finish - start_).count() << "ms"
                  << std::endl
                  << "Increased Physical Memory: "
                  << delta_rss << std::endl
                  << "Increased Virtual Memory: "
                  << delta_vsize << std::endl
                  << "User time: "
                  << delta_utime << std::endl
                  << "Sys time: "
                  << delta_stime << std::endl;


    } else {
        std::cout << "Error: Can't get system info." << std::endl;
        assert(false);
    }
}

// Monitor::~Monitor() {
//     if (isTypeChecked(MonitorType::ELAPSED_TIM)) {
//         auto finish = std::chrono::high_resolution_clock::now();
//         std::cout << "Total Elapsed Time: "
//                   << std::chrono::duration_cast<milli>(finish - start_).count()
//                   << "milliseconds\n";
//     }
// }

}  // namespace ymy
