#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base
{
    virtual void show() { cout << "Derived\n"; }
};

TEST(RTTI, typeid) {
    cout << typeid(Base).name() << endl;
    cout << typeid(Derived).name() << endl;
    Base *b = new Derived();
    cout << typeid(b).name() << endl;
    // b->__vptr
}