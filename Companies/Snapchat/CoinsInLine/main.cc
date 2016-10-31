#include <vector>
#include <iostream>
using namespace std;

int MaxOfA(const vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > f(n, vector<int>(n, 0));
    for (int i = 0; i < n - 1; ++i) {
        f[i][i] = nums[i];
        f[i][i + 1] = max(nums[i], nums[i + 1]);
    }
    f[n - 1][n - 1] = nums[n - 1];
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            f[j][j + i] = max(nums[j] + (nums[j + 1] > nums[j + i] ? f[j + 2][j + i] : f[i + 1][j + i - 1]), nums[j + i] + (nums[j] > nums[j + i - 1] ? f[j + 1][j + i - 1] : f[j][j + i - 2]));
        }
    }
    return f[0][n - 1];
}

int main() {
    vector<int> input = {3,7,2,1,4};
    cout << MaxOfA(input) << endl;
    return 0;
}
