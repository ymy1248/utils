#include <chrono>
#include <iostream>

namespace ymy {

using milli = std::chrono::milliseconds;

class Timer {
 public:
  Timer() :
    start_(std::chrono::high_resolution_clock::now())
  {}
  ~Timer() {
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<milli>(end - start_).count()
              << " milliseconds\n";
  }

 private:
  std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> start_;
};
}   // namespace ymy