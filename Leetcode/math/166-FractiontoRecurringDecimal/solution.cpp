#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string result;

    if (denominator == 0) return result;

    if (numerator == 0) return "0";

    if (numerator < 0 ^ denominator < 0) result += '-';

    long long n = abs((long long)numerator);

    long long d = abs((long long)denominator);

    result += to_string(n / d);

    if (n % d == 0) return result;

    result += '.';

    unordered_map<int, int> res_pos;

    for (long long r = n % d; r; r %= d) {
      if (res_pos.count(r)) {
        result.insert(res_pos[r], 1, '(');

        result += ')';

        break;
      }

      res_pos[r] = result.size();

      r *= 10;

      result += to_string(r / d);
    }

    return result;
  }
};

int main() {
  Solution s;
  cout << s.fractionToDecimal(1, 3) << endl;
  return 0;
}
