#include <iostream>
using namespace std;

class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0 || k == 0) return 0;
    int same = 0; // Representing the num of ways to print the current post if it has the same color with the previous post
    int diff = k; // Representing the num of ways to print the current post if it has different color with the previous post
    for (int i = 1; i < n; i++){
      int temp = same;
      same = diff; // If we choose to paint the current post with same color, than just equal to paint the previous post, but has to be different color.
      diff = (k-1) * (temp + diff); // If we choose a different color, then (k-1) ways.
    }
    return same + diff;
  }
};

int main()
{
  Solution s;
  cout << "8 posts and 5 colors: " << s.numWays(8, 5) << endl;
  return 0;
}
