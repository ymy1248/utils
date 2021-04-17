#include "../../ds/list.hpp"
#include <list>

using namespace std;

int main ()
{
  ymy::list<int> l;
  for (int i = 0; i < 10; ++i) {
    l.push_back(i);
  }
  std::cout << l;
  return 0;
}
