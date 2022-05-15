#include <gtest/gtest.h>
#include <iostream>
#include <static.hpp>

using namespace std;

int dup(int n)
{
    return n * 2;
}

int Widget1::s_var2 = Widget1::s_var3;
int Widget1::s_var1 = dup(100);
int Widget1::s_var4 = Widget1::s_var5;

TEST(static_test, test1) {
    // This is not guaranteed, dynamic initialization for static variable doesn't have specific order.
    // EXPECT_EQ(Widget1::s_var1, Widget1::s_var0);
    // EXPECT_EQ(Widget1::s_var3, Widget1::s_var2);
    // EXPECT_EQ(Widget1::s_var4, Widget1::s_var5);

    // To solve this issue please refer to: https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use
}