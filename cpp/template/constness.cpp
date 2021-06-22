#include <type_traits>
#include <assert.h>
#include"env.hpp"

using namespace std;

class Imp {
};
class Wrapper {
 public:
    Imp *imp;
    Wrapper() {
        cout << "Ctor\n";
    }
    void func() const {
        cout << "const func()\n";
    }
    void func() {
        cout << "non-const func()\n";
    }
    Wrapper(const Wrapper &that) {
        // cout << std::is_const<
        cout << "Const copy ctor wrapper\n";
        func();
    }
    Wrapper(Wrapper &that) {
        cout << "copy ctor wrapper\n";
        func();
    }
};

int main() {
    Wrapper a;
    const Wrapper b = a;
    Wrapper c = b;
    const Wrapper e = b;
}