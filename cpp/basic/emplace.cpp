#include <vector>
#include <gtest/gtest.h>

#include "widget.hpp"

using namespace std;

TEST(emplace, basic) 
{
    vector<Widget> container;
    container.push_back(Widget(0));
    // Directly create element inside the container
    container.emplace_back(1);
}