#include <iostream>

using namespace std;

class Widget {
public:
  Widget() { cout << "ctor" << endl; };
  Widget(const Widget &that) { cout << "copy ctor" << endl; }
  Widget(Widget &&that) { cout << "move ctor" << endl; }
  int val;
};

template<typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

template<typename T>
void foo(T&& w) {
  cout << "foo" << endl;
}

int main() {
  Widget w1;
  foo(w1);

}