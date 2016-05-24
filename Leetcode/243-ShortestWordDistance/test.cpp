//To test if '==' is supported for string
//To test the usage of abs().

#include <iostream>
#include <string>
#include <math.h> // Supporting abs()
using namespace std;

int main()
{
  string word1 = "coding";
  string word2 = "makes";
  string word3 = "coding";
  cout << (word1 == word3) << endl;
  cout << abs(0 - INT_MIN) << endl;
  return 0;
}

