#include <gtest/gtest.h>
#include <vector>
#include <boost/timer/timer.hpp>
#include "vector.hpp"

TEST(vector, push_back) {
  ymy::vector<int> ymyV;
  std::vector<int> stdV;

  int data_size = 1E8;

  boost::timer::cpu_timer timer;
  timer.start();
  for (int i = 0; i < data_size; ++i) {
    ymyV.push_back(i);
  }
  timer.stop();
  printf("ymy vector push_back: %s\n", timer.format().c_str());

  timer.start();
  for (int i = 0; i < data_size; ++i) {
    stdV.push_back(i);
  }
  timer.stop();
  printf("std vector push_back: %s\n", timer.format().c_str());

  for (int i = 0; i < data_size; ++i) {
    ASSERT_EQ(ymyV[i], i);
  }
}
