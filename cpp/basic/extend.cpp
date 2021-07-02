#include <env.hpp>

template<typename T>
class B {
 public:
    int _num;
    T _t;
};

template<typename T>
class D : public B<T> {
 public:
    D(T t) {
        this->_num = 10;
        this->_t = t;
    }
};

class Derived : public Base {
 public:
    Derived() {
        _num = 10;
    }
};

int main()
{
    D<int> d(20);
}