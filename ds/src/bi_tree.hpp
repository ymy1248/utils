/**
 * @file bi_tree.hpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <vector>

/**
 * @brief Binary index tree
 * 算法学习笔记(2) : 树状数组 - Pecco的文章 - 知乎 https://zhuanlan.zhihu.com/p/93795692
 * LeetCode: https://leetcode-cn.com/problems/count-good-triplets-in-an-array/
 */
class BinaryIndexTree
{
public:
    BinaryIndexTree(size_t size) : 
        _tree(size, 0)
    {}

    void 
    update(size_t idx, int x) 
    {
        for (; idx <_tree.size(); idx += lowBit(idx)) {
            _tree[idx] += x;
        }
    }

    int 
    get(size_t n) const
    {
        int ans = 0;
        for (; n; n -= lowBit(n))
            ans += _tree[n];
        return ans;
    }
    
    int
    get(size_t lo, size_t hi) const  
    {
        return get(hi) - get(lo - 1);
    }

private:
    size_t lowBit(size_t x) const { return x & (-x); }
    std::vector<int64_t> _tree;
};