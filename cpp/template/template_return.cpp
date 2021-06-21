#include <iostream>
#include "env.hpp"

using namespace std;

class Derived1 : public Base {
 public:
  Derived1() : Base(1) {}
};

class Derived0 : public Base {
 public:
  Derived0() : Base(0) {}
};

template <typename T>
class Handle {
 private:
  size_t _attrId;
};

template<typename T>
T max(T a, T b) {
  return a > b ? a : b;
}

template <typename Func>
class Op {
 public:
    void operator()() {
        Func::call();
    }
};

struct Function {
    static void call() {
        cout << "Call Function\n";
    }
};

template<typename Func>
Op<Func> foo() {
    return Op<Func>();
}

template <typename T>
T* get(Handle<T> handle) {
  T* ptr = new T();
  return ptr;
}

template<typename T>
void foo(T&& w) {
  cout << "foo" << endl;
}

int main() {
    auto op = foo<Function>();
    op();
    return 0;
}