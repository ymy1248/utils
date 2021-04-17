#include <vector>
#include <functional>

using namespace std;

template <typename T>
size_t bsearch(const vector<T> &v, function<bool(const vector<T>&, size_t)> check) {
  size_t lo = 0, hi = v.size() - 1;
  while (lo < hi) {
    size_t mid = lo + hi >> 1;
    if (check(v, mid)) lo = mid;
    else hi = mid + 1;
  }
  return lo;
}
