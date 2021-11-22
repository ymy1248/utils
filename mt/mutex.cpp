#include <gtest/gtest.h>
#include <iostream>
#include <thread>
#include "gtest/gtest_pred_impl.h"

using namespace std;

std::mutex mtx1;
std::mutex mtx2;

void logTest1(ostringstream *os) {
    std::lock_guard<std::mutex> lock(mtx1);
    for (int i = 0; i < 10; ++i) {
        *os << '1';
    }
    *os << "\n";
    mtx2.unlock();
}
void logTest2(ostringstream *os) {
    std::lock_guard<std::mutex> lock(mtx2);
    for (int i = 0; i < 10; ++i) {
        *os << '2';
    }
    *os << "\n";
}
void test(char c, char d) {
    cout << c << endl;
}

TEST(Mutex, basic) {
    ostringstream os;
    mtx2.lock();
    std::thread t1(logTest1, &os);
    std::thread t2(logTest2, &os);
    // t.join();
    t1.join();
    t2.join();
    EXPECT_EQ(os.str(), string("1111111111\n2222222222\n"));
}