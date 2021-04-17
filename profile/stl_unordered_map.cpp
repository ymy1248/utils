#include <unordered_map>
#include <iostream>
#include <vector>

#include "../util/timer.hpp"

uint32_t SIZE = 1e8;
void clear(std::vector<int> &data) {
  std::cout << "Clear\n";
  std::unordered_map<int, int> um;

  for (auto & n : data) {
    um[n] = 1;
  }
  ymy::Timer t;
  um.clear();
}

void swap(std::vector<int> &data) {
  std::cout << "Swap\n";
  std::unordered_map<int, int> um;

  for (auto & n : data) {
    um[n] = 1;
  }
  ymy::Timer t;
  std::unordered_map<int, int>().swap(um);
}

int main() {
  std::vector<int> data(SIZE);
  for (int i = 0; i < SIZE; ++i) {
    data[i] = rand() % (2*SIZE);
  }
  clear(data);
  swap(data);
  return 0;
}