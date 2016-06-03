#include "../myVector.h"

class Solution {
public:
  int findMin(vector<int>& nums) {
    int len = nums.size();
    int start = 0;
    int end = len - 1;
    int mid;
    while (start < end){
      if (end - start == 1) return min(nums[start], nums[end]);
      mid = start + (end - start) / 2;
      while (mid < end && nums[mid] == nums[mid + 1]) mid++;
      if (mid == end) {
        end = start + (end - start) / 2;
        continue;
      }
      if (nums[mid] > nums[mid+1]) return nums[mid+1];
      else{
        if (nums[mid] <= nums[end]) end = mid;
        else start = mid + 1;
      }
    }
    return nums[start];
  }
};

int main()
{
  int v[] = {1,2,3,4,5,0,0};
  vector<int> vec(&v[0], &v[0]+6);
  Solution s;
  cout <<s.findMin(vec);
  return 0;
}
