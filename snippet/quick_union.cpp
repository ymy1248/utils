/**
 * @file quick_union.cpp
 * @author ymy1248 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>

using namespace std;

class QuickUnion {
 public:
  vector<int> d_id;
  int d_size;

  explicit QuickUnion(int size) :
    d_id(size),
    d_size(size) {
    for (int i = 0; i < d_size; ++i) {
      d_id[i] = i;
    }
  }

  void connect(int from, int to) {
    d_id[getRoot(to)] = getRoot(from);
  }

  int getRoot(int id) {
    if (id == d_id[id]) return id;
    return getRoot(d_id[id]);
  }
};

class WeightedQuickUnion {
};
