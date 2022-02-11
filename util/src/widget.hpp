#include <iostream>

class Widget {
 public:

  Widget() {
    std::cout << "Base CTOR\n";
  }

  explicit Widget(int num) : _num(num) {
    std::cout << "Base " << _num << " CTOR\n";
  };

  Widget(const Widget &b) {
    _num = b._num;
    std::cout << "Base " << _num << " Copy CTOR\n";
  }
  Widget(const Widget &&b) {
    _num = b._num;
    std::cout << "Base " << _num << " Move CTOR\n";
  }
  Widget& operator=(const Widget &b) {
    _num = b._num;
    std::cout << "Base " << _num << " Copy Assignment\n";
    return *this;
  }
  Widget& operator=(const Widget &&b) {
    _num = b._num;
    std::cout << "Base " << _num << " Move Assignment\n";
    return *this;
  }
  ~Widget() {
    std::cout << "Base " << _num << " DTOR\n";
  }

  void echo() const;

  int _num;
};