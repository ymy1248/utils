#include <iostream>
#include <type_traits>

using namespace std;

template <typename T, typename = std::enable_if_t<(sizeof(T) >= 4)>>
void foo(T t) {
  cout << "T size is larger or equal to 4.\n";
}

//! Can't do typename enable_if overloading. Redefinition error.
// template <typename T, typename = std::enable_if_t<(sizeof(T) < 4)>>
// void foo(T t) {
//   cout << "T size is less than 4\n";
// }

template <typename T>
std::enable_if_t<(sizeof(T) >= 4), void>
foo1(T t) {
  cout << "T size is larger or equal to 4.\n";
}

template <typename T>
std::enable_if_t<(sizeof(T) < 4), void>
foo1(T t) {
  cout << "T size is less than 4. \n";
}

template <typename T>
void foo2Impl(T t, std::true_type) {
  cout << __FUNCTION__ << ": T size is larger or equal to 4.\n";
}

template <typename T>
void foo2Impl(T t, std::false_type) {
  cout << __FUNCTION__ << ": T size is less than 4.\n";
}

template <typename T>
void foo2(T t) {
  foo2Impl(t, sizeof(T) >= 4);
}

int main() {
  int i = 0;
  uint16_t s = 0;
  foo(i);

  foo1(i);
  foo1(s);

  foo2(i);
}