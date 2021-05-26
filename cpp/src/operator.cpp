#include <iostream>

using namespace std;

class ptr{
public:
  ptr* operator->() {
    cout << "operator->" << endl;
    return nullptr;
  }
};

int main() {
  ptr p;
  p->();
}
