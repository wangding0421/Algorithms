#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void wiggleSort(vector<int>& nums) { //My solution causes O(nlog) time
    int len = nums.size();
    if (!len) return;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < len - 1; i += 2){
      swap(nums[i], nums[i+1]);
    }
    return;
  }

  void wiggleSortOptimal(vector<int>& nums) {
    int len = nums.size();
    for (int i = 1; i < len; i++){
      if (((i&1) && nums[i] < nums[i-1]) || (!(i&1) && nums[i] > nums[i-1])) swap(nums[i], nums[i-1]);
    }
    return;
  }
};

int main()
{
  int v[] = {1,2,3,4,5};
  vector<int> vec(&v[0], &v[0]+5);
  Solution s;
  s.wiggleSortOptimal(vec);
  for (int i = 0; i < 5; i++){
    cout << vec[i];
  }

  return 0;
}


