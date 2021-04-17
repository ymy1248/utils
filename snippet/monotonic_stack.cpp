#include <iostream>
#include <list>
#include <vector>
// find the first larger element index

using namespace std;

vector<int> left_first_larger_element(vector<int> &nums)
{
  vector<int> ans(nums.size(), 0);
  list<int> s;

  for (size_t i = 0; i < nums.size(); ++i) {
    while (!s.empty() && nums[s.back()] <= nums[i]) {
      s.pop_back();
    }
    if (s.empty()) ans[i] = -1;
    else ans[i] = s.back();
    s.push_back(i);
  }
  return ans;
}

int main()
{
  vector<int> test = {5,4,2,1,6,5,4,2,6,7};
  auto ans = left_first_larger_element(test);
  for (auto n : ans) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}

