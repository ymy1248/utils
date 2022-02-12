#include <vector>
#include <deque>
#include <set>
#include <gtest/gtest.h>

#include "widget.hpp"

using namespace std;

TEST(emplace, basic) 
{
    {
        vector<Widget> container;
        // Directly create element inside the container
        container.emplace_back(1);
    }
    EXPECT_EQ(Widget::_ctor, 1);
    EXPECT_EQ(Widget::_dtor, 1);

    Widget::initRefCount();
    {
        vector<Widget> container;
        // Move into container
        container.push_back(Widget(0));
    }
    EXPECT_EQ(Widget::_ctor, 2);
    EXPECT_EQ(Widget::_dtor, 2);

    Widget::initRefCount();
    {
        vector<Widget> container;
        // Move into container
        container.emplace_back(Widget(0));
    }
    EXPECT_EQ(Widget::_ctor, 2);
    EXPECT_EQ(Widget::_dtor, 2);
}

TEST(emplace, emplace_front)
{
    deque<Widget> container;
    container.emplace_front(1);
}

TEST(emplace, emplace)
{
    set<Widget> container;
    container.emplace(1);
}