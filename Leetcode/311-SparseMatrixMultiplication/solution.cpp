#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {//My solution Takes mA * nB * nAmB time
    vector<vector<int> > result;
    int mA = A.size();
    if (!mA) return result;
    int nAmB = A[0].size();
    if (!nAmB) return result;
    int nB = B[0].size();
    for (int i = 0; i < mA; i++){
      vector<int> currentRow(nB);
      for (int j = 0; j < nB; j++){
        int currentResult = 0;
        for (int k = 0; k < nAmB; k++){
          currentResult += (A[i][k] && B[k][j]) ? A[i][k] * B[k][j] : 0;
        }
        currentRow[j] = currentResult;
      }
      result.push_back(currentRow);
    }
    return result;
  }

  vector<vector<int> > multiplyOptimal(vector<vector<int> >& A, vector<vector<int> >& B) {
    int mA = A.size();
    int mB = B.size();
    int nAmB = A[0].size();
    int nB = B[0].size();
    vector<vector<int> > result(mA, vector<int>(nB, 0));
    for (int i = 0; i < mA; i++) {
      for (int j = 0; j < nAmB; j++) {
        if (A[i][j] != 0){
          for (int k = 0; k < nB; k++){
            result[i][k] += A[i][j] * B[j][k];
          }
        }
      }
    }
    return result;
  }
};

int main()
{
  vector<vector<int> > A(2, vector<int>(3, 0));
  vector<vector<int> > B(3, vector<int>(3, 0));

  A[0][0] = 1;
  A[1][0] = -1;
  A[1][2] = 3;
  B[0][0] = 7;
  Solution s;

  vector<vector<int> > result = s.multiplyOptimal(A, B);

  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[0].size(); j++) {
      cout << result[i][j] << ',';
    }
    cout << endl;
  }



  return 0;
}

