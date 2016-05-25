#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:

  int maxSubArrayLen(vector<int>& nums, int k) {
    int result = 0;
    int len = nums.size();
    if (!len) {
      return result;
    }
    int currentSum = 0;
    sumMap[0] = -1; // Important initial value!!
    for (int i = 0; i < len; i++) {
      currentSum += nums[i];
      if (sumMap.count(currentSum - k)){
        result = max(result, i - sumMap[currentSum - k]);
      }
      if (!sumMap.count(currentSum)){
        sumMap[currentSum] = i;
      }
    }
    return result;
  }
private:
  unordered_map<int, int> sumMap;
};

int main()
{
  int vv[] = { 1,-1,5,-2,3 };
  vector<int> nums(&vv[0], &vv[0]+5);
  int k = 3;
  Solution s;
  cout << s.maxSubArrayLen(nums, k) << endl;
  return 0;
}

