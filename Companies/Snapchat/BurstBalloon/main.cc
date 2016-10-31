#include <vector>
#include <iostream>
#include <algorithm>

int maxCoins(const std::vector<int>& nums) {
    std::vector<int> local_nums = nums;
    int n = local_nums.size();
    local_nums.insert(local_nums.begin(), 1);
    local_nums.push_back(1);
    std::vector<std::vector<int> > dp(n + 2, std::vector<int>(n + 2, 0));
    for (int len = 1; len <= n; ++len) {
        for (int left = 1; left <= n - len + 1; ++left) {
            int right = left + len - 1;
            for (int k = left; k <= right; ++k) {
                dp[left][right] = std::max(dp[left][right], local_nums[left - 1] * local_nums[k] * local_nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
            }
        }
    }
    return dp[1][n];
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = {3,1,5,8};
    std::cout << maxCoins(nums) << std::endl;
    return 0;
}
