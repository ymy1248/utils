#include<iostream>

using namespace std;

using CpyCtorFunc = void*(*)(const void*x);

class Widget {
 public:
  ~Widget() {
    cout << "Dtor" << endl;
  }
  Widget() { cout << "Default ctor" << endl; };
  Widget(const Widget &w) {
    cout << "Cpy ctor" << endl;
  }
};

int main() {
  void(*destory)(const void*);
  Widget x;
  destory = [](const void* x) { static_cast<const Widget*>(x)->~Widget(); };
  destory(&x);
  CpyCtorFunc cpyCtor = [](const void *x) { 
    return static_cast<void*>(new Widget(*static_cast<const Widget*>(x))); 
  };
  return 1;
}