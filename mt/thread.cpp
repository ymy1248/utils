/**
 * @file thread.cpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief Learning std thread.
 * @version 0.1
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;


TEST(Thread, basic) 
{
    class Functor {
     public:
        std::mutex &_mtx;
        void operator()() {
            _mtx.try_lock();
            cout << "Do something!" << endl;
            _mtx.unlock();
        }
        explicit Functor(mutex &mtx) : _mtx(mtx) 
        {}
    };
    //! This causes ambiguity, it is like a function declaration.
    // thread myThread(Functor());

    // Two ways to resolve this problem.
    // Initialize list.
    std::mutex mtx;
    thread myThread1{Functor(mtx)};
    // Double pair parentheses
    thread myThread2((Functor(mtx)));
    myThread1.join();
    myThread2.join();
}

TEST(Thread, join) 
{
    class Functor {
     public:
        int &_i;
        Functor(int &i) : _i(i) {}
        void operator()()
        {
            for (unsigned j = 0; j < 1E8; ++j) {
                ++_i;
            }
        }
    };
    int i = 0;
    thread t1((Functor(i)));
    t1.join();
    EXPECT_EQ(t1.joinable(), false);
    EXPECT_EQ(i, 1E8);

    int i2 = 0;
    thread t2((Functor(i2)));
    t2.detach();
    EXPECT_NE(i2, 1E8);
    // Sleep for 1 sec to ensure i2 still allocated, otherwise segv.
    std::this_thread::sleep_for(std::chrono::seconds(1));
}