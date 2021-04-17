/**
 * @file monitor.h
 * @author ymy1248
 * @brief 
 * @version 0.1
 * @date 2021-01-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UTIL_MONITOR_HPP_
#define UTIL_MONITOR_HPP_

#include <unistd.h>
#include <iostream>

namespace ymy {

using milli = std::chrono::milliseconds;
typedef struct vmtotal vmtotal_t;

enum class MonitorType : uint32_t {
    PHYSICAL_MEM        = 0x01,
    VIRTUAL_MEM         = 0x02,
    ELAPSED_TIM         = 0x04,
    ALL                 = 0x07
};

struct ProcInfo {
    size_t rss, vsize;
    double utime, stime;
};

class Monitor {
 public:
    explicit Monitor(MonitorType type = MonitorType::ALL);
    ~Monitor();

 private:
    bool isTypeChecked(MonitorType type) const { return (uint32_t)type | (uint32_t)type_; }
    int getProcInfo(pid_t pid, ProcInfo &rpd);

    MonitorType type_;
    std::chrono::high_resolution_clock::time_point start_;
    pid_t pid_;
    size_t rss_;
    size_t vsize_;
    double utime_;
    double stime_;

};

}  // namespace ymy

#endif  // UTIL_MONITOR_HPP_
