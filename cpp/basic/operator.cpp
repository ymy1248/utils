#include <iostream>

using namespace std;

class ptr{
public:
  ptr* operator->() {
    cout << "operator->" << endl;
    return this;
  }

  int a = 0;
};

int main() {
  ptr p;
  cout << p->a << endl;
}