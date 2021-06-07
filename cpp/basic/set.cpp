#include <set>
#include <iostream>

using namespace std;

int main() {
  set<int> s;
  for (int i = 0; i < 10; ++i) {
    s.insert(i);
  }
  auto it = s.find(5);
  // cout << it - s.begin() << endl;
}