/*Hilbert Curve
1  12
   03
   
2 5 6 9  10
  4 7 8  11
  3 2 13 12
  0 1 14 15
3 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void copy(vector<vector<int> >& result, int offset, int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			result[i][j] += offset;
		}
	}
}

void FlipMain(vector<vector<int> >& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		}
	}
}

void FlipSecond(vector<vector<int> >& matrix) {
	int n = matrix.size();
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

vector<vector<int> > generateHC(int n) {
	int width = pow(2, n);
	vector<vector<int> > result(width, vector<int>(width));
	result[0][0] = 2;
	result[0][1] = 3;
	result[1][0] = 1;
	result[1][1] = 4;

	if (n <= 1) return result;

	vector<vector<int> >left_lower = generateHC(n - 1);
	FlipMain(left_lower);
	vector<vector<int> >left_upper = generateHC(n - 1);
	vector<vector<int> >right_upper = left_upper;
	vector<vector<int> >right_lower = generateHC(n - 1);
	FlipSecond(right_lower);

	for (int i = width / 2; i < width; ++i) {
		for (int j = 0; j < width / 2; ++j) {
			result[i][j] = left_lower[i - width/2][j];
		}
	}

	for (int i = 0; i < width / 2; ++i) {
		for (int j = 0; j < width / 2; ++j) {
			result[i][j] = left_upper[i][j] + width / 2 * width / 2;
		}
	}

	for (int i = 0; i < width / 2; ++i) {
		for (int j = width / 2; j < width; ++j) {
			result[i][j] = right_upper[i][j - width/2] + width / 2 * width;
		}
	}

	for (int i = width / 2; i < width; ++i) {
		for (int j = width / 2; j < width; ++j) {
			result[i][j] = right_lower[i - width / 2][j - width/2] + width / 2 * width / 2 * 3;
		}
	}

	return result;
}

int main() {
	vector<vector<int> > hc = generateHC(4);
	for (int i = 0; i < hc.size(); ++i) {
		for (int j = 0; j < hc[i].size(); ++j) {
			cout << hc[i][j] << "   ";	
		}
		cout << endl;
	}
	return 0;
}
