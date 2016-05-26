#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isPowerOfFour(int num) {
    if (num <= 0) return false;
    if (num == 1) return true;
    while (num > 1){
      if (num % 4 != 0) return false;
      num /= 4;
    }
    return true;
  }

  bool isPowerOfFourSol2(int num){
    return num > 0 && (num & (num-1)) == 0 && (num - 1) % 3 == 0;
    /*
      Proof:

      First, Any number passes "n^(n-1)==0" must be powers of 2. Second, all numbers above could be further categorized to 2 class. A: all numbers that are 2^(2k+1) and B: all numbers that 2^(2k). Third, we could show that 2^(2k+1)-1 could not pass the test of (n-1)%3==0. (by induction) So all A are ruled out, leaving only B, which is power of 4.
      
      Proof (by induction) 4^(n+1) - 1 = 44^n -1 = 34^n + 4^n-1. The first is divided by 3, the second is proven by induction hypothesis
     */
  }
};

int main()
{
  Solution s;
  cout << "Is 12 power of 4?: " << s.isPowerOfFour(12) << endl;
  cout << "Is 16 power of 4?: " << s.isPowerOfFour(16) << endl;

  cout << "Bit operations:" << endl;
  cout << "Is 12 power of 4?: " << s.isPowerOfFourSol2(12) << endl;
  cout << "Is 16 power of 4?: " << s.isPowerOfFourSol2(16) << endl;
  return 0;
}
