#include <gtest/gtest.h>
#include <iostream>
#include <shared_mutex>
#include <thread>

#include "env.hpp"

using namespace std;

std::mutex mtx;

void log(ostringstream *os, char c) {
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < 10; ++i) {
        (*os) << c;
    }
    (*os) << "\n";
}

TEST(mutex, basic) {
    ostringstream os;
    std::thread t1(log, &os, '1');
    std::thread t2(log, &os, '2');
    t1.join();
    t2.join();
    EXPECT_EQ(os.str(), string("1111111111\n2222222222\n"));
}