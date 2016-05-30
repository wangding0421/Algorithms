#include <iostream>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 1) return false;
    bool isPrime[n];
    for (int i = 2; i < n; i++){
      isPrime[i] = true;
    }
    for (int i = 2; i * i < n; i++){
      if (!isPrime[i]) continue;
      for (int j = i*i; j < n; j += i){
        isPrime[j] = false;
      }
    }
    int result = 0;
    for (int i = 2; i < n; i++){
      result += isPrime[i];
    }
    return result;
  }
};

int main()
{
  Solution s;
  cout << s.countPrimes(100) << endl;
  return 0;
}
