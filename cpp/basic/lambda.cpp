#include "env.hpp"

//!error out we can't have auto type function
// using CastFunc = auto(*)(void*); 
class Derived0 : public Base {
 public:
  Derived0() : Base(0) {}
};

class Derived1 : public Base {
 public:
  Derived1() : Base(1) {}
};

template<typename T>
auto func(T val) {
  auto convert = [](void* x) { return *static_cast<T*>(x); };
  return convert(&val);
}

int foo(void* ptr) {
  return 1;
}

int main() {
  auto (*fi)(void*) = foo;
  Derived0 d0;
  auto d = func(d0);
}