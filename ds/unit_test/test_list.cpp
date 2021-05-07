#include <gtest/gtest.h>
#include <list>
#include <boost/timer/timer.hpp>
#include "list.hpp"

TEST(list, modify) {
  std::list<size_t> std_l;
  ymy::list<size_t> ymy_l;

  size_t data_size = 1E7;

  boost::timer::cpu_timer timer;
  timer.start();
  for (size_t i = 0; i < data_size; ++i) {
    ymy_l.push_back(i);
  }
  timer.stop();
  printf("ymy list push_back: %s\n", timer.format().c_str());


  timer.start();
  for (size_t i = 0; i < data_size; ++i) {
    std_l.push_back(i);
  }
  printf("stl list push_back: %s\n", timer.format().c_str());
}
