#ifndef UTIL_SRC_ENV_HPP_
#define UTIL_SRC_ENV_HPP_

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

class Base {
 public:
  Base() {
    std::cout << "Base CTOR\n";
  }

  explicit Base(int num) : _num(num) {
    std::cout << "Base " << _num << " CTOR\n";
  };

  Base(const Base &b) {
    _num = b._num;
    std::cout << "Base " << _num << " Copy CTOR\n";
  }
  Base(const Base &&b) {
    _num = b._num;
    std::cout << "Base " << _num << " Move CTOR\n";
  }
  Base& operator=(const Base &b) {
    _num = b._num;
    std::cout << "Base " << _num << " Copy Assignment\n";
    return *this;
  }
  Base& operator=(const Base &&b) {
    _num = b._num;
    std::cout << "Base " << _num << " Move Assignment\n";
    return *this;
  }
  ~Base() {
    std::cout << "Base " << _num << " DTOR\n";
  }

  void echo() const;

  int _num;
};

#endif  // UTIL_SRC_ENV_HPP_