#include <set>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  set<int> s;
  for (int i = 0; i < 10; ++i) {
    s.insert(i);
  }
  auto it = s.find(5);
  // cout << it - s.begin() << endl;


    vector<int> from(10, 0);
    for (int i = 0; i < 10; ++i) {
        from[i] = i;
    }
    vector<int> to(10,0);
    std::copy(from.begin(), from.end(), std::back_inserter(to));
    for (int i = 0; i < to.size(); ++i) {
        cout << to[i] << endl;
    }
}