#include <env.hpp>

using namespace std;

int main() {
    int *arr = new int[20];
    cout << "sizeof(arr) = " << sizeof(*arr) << endl;
}