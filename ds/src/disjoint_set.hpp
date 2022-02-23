/**
 * @file disjoint_set.hpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief Weighted Disjoint Set. Support connected component in graph.
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector>
#include <deque>
#include <unordered_map>
#include <iostream>

namespace ymy {

template <typename Container = std::vector<size_t>> 
class TrivalDjSet {
public:
    /**
     * @brief Get the Root object. Enhancement: with each query, connect previous node parent to current parent to decrease the tree height.
     * 
     * @param n 
     * @return size_t 
     */
    size_t getRoot(const size_t &n) const
    {
        size_t next;
        size_t root = n;
        size_t prev = n;
        while (root != (next = _parent[root])) {
            _parent[prev] = next;
            prev = root;
            root = next;
        }
        return root;
    }

private:
    mutable Container _parent;
    Container _height;
};

/**
 * @brief Typical disjoint set. Always connect shorter tree to higher.
 * 
 * @tparam Container 
 */
template <typename Container = std::vector<size_t>> 
class DisjointSet {
private:
    mutable Container _parent;
    Container _height;

public:
    explicit DisjointSet(size_t size) : 
        _parent(size), _height(size, 0) 
    {
        for (size_t idx = 0; idx < size; ++idx) {
            _parent[idx] = idx;
        }
    }

    void connect(size_t n0, size_t n1) 
    {
        size_t r0 = getRoot(n0);
        size_t r1 = getRoot(n1);
        if (r0 == r1) return;
        // O(n * m) algorithm
        // _parent[r0] = r1;
        // return;
        size_t h0 = _height[r0];
        size_t h1 = _height[r1];

        // connect tree to taller one
        // O(n log_k M) algorithm
        if (h0 < h1) {
            _parent[r0] = r1;
        } else {
            // Do NOT overoptimize to connect smaller tree to taller tree if height is same. The node number comparison increase runtime.
            _parent[r1] = r0;
            if (h0 == h1) {
                ++_height[r0];
            }
        }
    }

    size_t getRoot(const size_t &n) const
    {
        size_t parent = _parent[n];
        if (n == _parent[n]) return n;
        return getRoot(parent);
    }

    size_t getNumOfCC() const
    {
        size_t num = 0;
        for (size_t i = 0; i < _parent.size(); ++i) {
            if (_parent[i] == i) {
                ++num;
            }
        }
        return num;
    }

    std::deque<std::deque<size_t>> getCC() const
    {
        std::deque<std::deque<size_t>> cc;
        std::unordered_map<size_t, size_t> rootToIdx;

        for (size_t i = 0; i < _parent.size(); ++i) {
            size_t root = getRoot(i);
            auto it = rootToIdx.find(root);
            if (it == rootToIdx.end()) {
                cc.emplace_back(1, i);
                rootToIdx[root] = cc.size() - 1;
            } else {
                cc[it->second].push_back(i);
            }
        }
        return cc;
    }

    void show(std::ostream &out = std::cout) const
    {
        out << "parent: {";
        for (size_t idx = 0; idx < _parent.size(); ++idx) {
            out << idx << ": " << _parent[idx] << ", ";
        }
        out << "}" << std::endl;

        out << "height: {";
        for (size_t idx = 0; idx < _height.size(); ++idx) {
            out << idx << ": " << _height[idx] << ", ";
        }
        out << "}" << std::endl;
    }
};

}   // namespace ymy