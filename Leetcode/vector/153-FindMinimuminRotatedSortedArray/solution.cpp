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
      if (nums[mid] > nums[mid+1]) return nums[mid+1];
      if (nums[mid - 1] > nums[mid]) return nums[mid];
      else{
        if (nums[mid] < nums[end]) end = mid-1;
        else if (nums[mid] > nums[end]) start = mid+1;
      }
    }
    return nums[start];
  }
};

int main()
{
  int v[] = {1,2,3,4,5,6,7,8,9,0};
  vector<int> vec(&v[0], &v[0]+10);
  Solution s;
  cout <<s.findMin(vec);
  return 0;
}
