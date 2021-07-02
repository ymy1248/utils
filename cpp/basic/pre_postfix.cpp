#include "env.hpp"

using namespace std;

class Widget {
 public:
    Widget& operator++() {
        cout << "pre\n";
        ++n;
        return *this;
    }

    // You want to make the ++ operator work like the standard operators
    // The simple way to do this is to implement postfix in terms of prefix.
    //
    Widget operator++(int) {    // dummy parameter
        cout << "post\n";
        auto tmp(*this);
        ++(*this);
        return tmp;
    }
    int n = 0;
};

int main() {
    Widget w;
    w++;
    ++w;
}