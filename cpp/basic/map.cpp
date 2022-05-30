#include <gtest/gtest.h>
#include <map>
#include <deque>

using namespace std;

TEST(map, basic)
{
    map<int, deque<int>> m;
    auto [iter, succeed] = m.insert({1, {1}});
    EXPECT_EQ(succeed, true);
    EXPECT_EQ(m.size(), 1);
}