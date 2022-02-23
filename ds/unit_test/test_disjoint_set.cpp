/**
 * @file test_disjoint_set.cpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>
#include <gtest/gtest.h>
#include <deque>
#include <random>
#include <algorithm>
#include <utility>
#include "disjoint_set.hpp"

using namespace ymy;

TEST(disjoint_set, basic)
{
    DisjointSet<std::vector<size_t>> ds(5);
    EXPECT_EQ(ds.getCC().size(), 5);
    ds.connect(0, 1);
    ds.connect(2, 3);
    ds.connect(1, 3);
    EXPECT_EQ(ds.getCC().size(), 2);
    ds.show();
}

size_t n = 21000;
std::deque<std::pair<size_t,size_t>> generateData() {
    std::deque<std::pair<size_t, size_t>> data;
    for (size_t from = 0; from < 200; ++from) {
        for (size_t to = from + 1; to < 200; ++to) {
            data.emplace_back(from, to);
        }
    }
    std::vector<size_t> randomData(1000);
    for (size_t i = 0; i < 1000; ++i) {
        randomData[i] = i + 1000;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(randomData.begin(), randomData.end(), g);
    for (int i = 0; i < randomData.size() - 1; ++i) {
        data.emplace_back(randomData[i], randomData[i+1]);
    }
    return data;
}

TEST(disjoint_set, stress)
{
    for (int i = 0; i < 1E2; ++i) {
        DisjointSet ds(n);
        auto data = generateData();
        for (auto &p : data) {
            ds.connect(p.first, p.second);
        }
        EXPECT_EQ(ds.getNumOfCC(), 19802);
    }
}

TEST(disjoint_set, stress_deuqe)
{
    for (int i = 0; i < 1E2; ++i) {
        DisjointSet<std::deque<size_t>> ds(n);
        auto data = generateData();
        for (auto &p : data) {
            ds.connect(p.first, p.second);
        }
        EXPECT_EQ(ds.getNumOfCC(), 19802);
    }
}