#include <math.h>
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    //[3, 5, 8, 1, 3]
    int length = nums.size();

    if (length < 2) return 0;
    // store the minimum number in the array (e.g. 1)
    int min_num = INT_MAX;

    // store the maximum number in the array (e.g. 8)
    int max_num = INT_MIN;
    for (int i = 0; i < length; ++i) {
      min_num = min(min_num, nums[i]);
      max_num = max(max_num, nums[i]);
    }

    if (min_num == max_num) return 0;

    // store the gap between each bucket in the array (e.g. 2)
    int gap = ceil(double((max_num - min_num)) / (length - 1));

    // vectors store the min and max in each bucket
    vector<int> min_gap(length - 1, INT_MAX);
    vector<int> max_gap(length - 1, INT_MIN);

    // Put numbers into their buckets
    for (int i = 0; i < length; ++i) {
      if (nums[i] == min_num || nums[i] == max_num) continue;
      int current_gap_id = (nums[i] - min_num) / gap;
      min_gap[current_gap_id] = min(min_gap[current_gap_id], nums[i]);
      max_gap[current_gap_id] = max(max_gap[current_gap_id], nums[i]);
    }

    int ans = INT_MIN;
    int pre = min_num;
    // Aggregate the count array, to represent the index of each element in
    // sorted result;
    for (int i = 0; i < length - 1; ++i) {
      if (min_gap[i] == INT_MAX && max_gap[i] == INT_MIN) continue;
      ans = max(ans, min_gap[i] - pre);
      pre = max_gap[i];
    }
    ans = max(ans, max_num - pre);
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums{3, 5, 8, 1, 3};
  cout << s.maximumGap(nums) << endl;
  return 0;
}
