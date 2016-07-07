#include "../myVector.h"

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k == 0) return false;

    vector<pair<int, int> > num_index;

    for (int i = 0; i < nums.size(); ++i) {
      num_index.push_back(make_pair(nums[i], i));
    }

    sort(num_index.begin(), num_index.end(),
         [](const pair<int, int>& first, const pair<int, int>& second) {
           return first.first < second.first;
         });

    int fast = 0;

    int slow = 0;

    for (; fast < num_index.size(); ++fast) {
      while ((long long)num_index[fast].first - num_index[slow].first > t)
        ++slow;

      for (int i = slow; i < fast; ++i) {
        if (abs(num_index[i].second - num_index[fast].second) <= k) return true;
      }
    }

    return false;
  }
};

int main() {
  int v[] = {1, 2, 3, 4, 5, 0, 0};
  vector<int> vec(&v[0], &v[0] + 6);
  Solution s;
  cout << s.containsNearbyAlmostDuplicate(vec, 1, 1);
  return 0;
}
