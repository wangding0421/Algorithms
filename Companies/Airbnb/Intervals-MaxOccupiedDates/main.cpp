#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

bool MyCompare(const pair<int, int>& first, const pair<int, int>& second) {
	return first.first <= second.first;
}

int GetMaxOccupiedDates (vector<pair<int, int> > dates) {
	int n = dates.size();
	sort(dates.begin(), dates.end(), MyCompare);
	vector<int> next(n, n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (dates[j].first > dates[i].second) {
				next[i] = j;
				break;
			}
		}
	}
	vector<int> f(n + 1);
	f[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		f[i] = max(f[i + 1], 1 + f[next[i]]);
	}
	return f[0];
}

int main() {
	vector<pair<int, int> > dates;
	dates.push_back(make_pair(0, 30));
	dates.push_back(make_pair(5,10));
	dates.push_back(make_pair(15, 20));
	dates.push_back(make_pair(21,39));
	cout << GetMaxOccupiedDates(dates);
	return 0;
}
