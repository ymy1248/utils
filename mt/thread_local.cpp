#include<gtest/gtest.h>
#include<thread>

thread_local int a = 0;
TEST(thread_local, basic)
{
    auto f = []() {
        a = 0;
        ++a;
        EXPECT_EQ(a, 1);
    };

    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();

    EXPECT_EQ(a, 0);
}