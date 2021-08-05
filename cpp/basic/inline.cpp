#include "env.hpp"

using namespace std;

class Test {
 public:
    void foo() {
        cout << "test" << endl;
    }
    inline void foo2();
};

inline void Test::foo2() {
    cout << "test" << endl;
}

int main() {
    Test t;
    t.foo2();
    return 0;
}