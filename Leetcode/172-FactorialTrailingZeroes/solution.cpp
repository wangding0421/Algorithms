/*
  See explaination at: https://leetcode.com/discuss/19847/simple-c-c-solution-with-detailed-explaination
 */
#include <iostream>
using namespace std;

class Solution
{
public:

  int trailingZeroes(int n) {
    int result = 0;
    for (long long i = 5; n/i > 0; i *= 5){
      result += n/i;
    }
    return result;
  }
};

int main()
{
  Solution s;
  cout << "Result of 4616 is: " << s.trailingZeroes(4616) << endl;
  return 0;
}


