#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
using VoidIfLarge = std::enable_if_t<(sizeof(T) >= 4), void>;

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
VoidIfLarge<T>
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

template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
void foo3(T t) {
  cout << __FUNCTION__ << endl;
}

template <typename T>
void foo2Impl(T t, std::false_type) {
  cout << __FUNCTION__ << ": T size is less than 4.\n";
}

template <typename T>
void foo2(T t) {
  foo2Impl(t, sizeof(T) >= 4);
}

// Enable if for ctor
template <typename T>
class Widget{
 public:
    template<typename U = T>
    explicit Widget(typename std::enable_if<is_same<U, int>::value>::type* = nullptr) {
        cout << "int ctor\n";
    }

    template<typename U = T>
    explicit Widget(T f, typename std::enable_if<is_same<U, float>::value>::type* = 0) {
        cout << "float ctor: " << f << endl;
    }
};


// Better way to SFINAE a CTOR, thanks to RL
template <typename T, bool b = false>
class MYCLASS
{
    public:

    template < typename typeT = T, bool myB = b, typename std::enable_if_t<myB && std::is_same_v<typeT, int>, bool > = true >
    MYCLASS(T a);

    // template < typename typeT = T, bool myB = b, typename std::enable_if_t<myB && std::is_same_v<typeT, int>, bool > = true >
    // MYCLASS(T a) { 
    //     // static_assert(std::is_same<T, double>::value);
    //     x = a;
    // }
    void print () {std::cout << x << std::endl;}
    
    int x;
};

template <typename T, bool b>
template <typename typeT, bool myB, typename std::enable_if_t<myB && std::is_same_v<typeT, int>, bool >>
MYCLASS<T, b>::MYCLASS(T a) {
    x = a;
}

int main() {
    int i = 0;
    uint16_t s = 0;
    foo(i);

    foo1(i);
    foo1(s);

    // Widget<int> wi(1);
    Widget<float> wf(1.0);

    MYCLASS<double, true> x(200.0);
    x.print();

    return 0;
}