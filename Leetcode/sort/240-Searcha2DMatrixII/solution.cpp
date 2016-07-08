#include <math.h>
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();

    if (m == 0) return false;

    int n = matrix[0].size();

    if (n == 0) return false;

    int row = 0;

    int col = n - 1;

    while (row <= m - 1 && col >= 0) {
      if (matrix[row][col] == target) {
        return true;

      } else if (matrix[row][col] > target) {
        --col;

      } else {
        ++row;
      }
    }

    return false;
  }
};

int main() { return 0; }
