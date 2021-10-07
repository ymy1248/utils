#include <thread>
#include <iostream>

using namespace std;

int foo(int n) {
    for (int i = 0; i < n; ++i) {
        cout << i << endl;
    }
    return 0;
}

int main() {
    std::thread t(foo, 10);
    std::thread t1(foo, 10);
    t.join();
    t1.join();
    return 0;
}