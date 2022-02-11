/**
 * @file smart_ptr.cpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief Smart pointers in STL.
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<gtest/gtest.h>
#include<memory>
#include<iostream>

#include"widget.hpp"

using namespace std;

TEST(shared_ptr, basic) {
    std::shared_ptr<Widget> widgetPtr = std::make_shared<Widget>();
    EXPECT_EQ(widgetPtr.use_count(), 1);
    EXPECT_EQ(sizeof(widgetPtr), 16); // Ptr + ref counter ptr
}

TEST(shared_ptr, dtor) {
    auto dtor1 = [](Widget *w) {
        cout << "dtor1 is called" << endl;
        delete w;
    };
    auto dtor2 = [](Widget *w) {
        cout << "dtor2 is called" << endl;
        delete w;
    };

    std::shared_ptr<Widget> widgetPtr1(new Widget, dtor1);
    widgetPtr1 = std::make_shared<Widget>(1);
    std::shared_ptr<Widget> widgetPtr2(new Widget, dtor2);
    widgetPtr2 = std::make_shared<Widget>(2);
    widgetPtr1 = widgetPtr2;
}
