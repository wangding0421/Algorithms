#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include <math.h>
using namespace std;

bool MyCompare(const pair<int, int>& first, const pair<int, int>& second) {
	return first.first <= second.first;
}

struct StructComp {
	bool operator() (const pair<int, int>& first, const pair<int, int>& second) {
		return first.second >= second.second;
	}
};
vector<vector<pair<int, int> > > MeetingRooms(vector<pair<int, int> >& intervals) {
	sort(intervals.begin(), intervals.end(), MyCompare);
	vector<set<pair<int, int>, StructComp> > rooms;

	for (const auto& i : intervals) {
		bool newroom = true;
		for (int j = 0; j < rooms.size(); ++j) {
			if (rooms[j].empty() || rooms[j].begin()->second <= i.first) {
				rooms[j].insert(i);
				newroom = false;
				break;
			}
		}
		if (newroom) {
			set<pair<int, int>, StructComp> new_heap;
			new_heap.insert(i);
			rooms.push_back(new_heap);
		}
	}
	vector<vector<pair<int, int> > > result;
	for (int i = 0; i < rooms.size(); ++i) {
		vector<pair<int, int> > one_room (rooms[i].begin(), rooms[i].end());
		result.push_back(one_room);
	}
	return result;
}

int main() {
	vector<pair<int, int> > dates;
	dates.push_back(make_pair(5,10));

	dates.push_back(make_pair(0, 30));
	dates.push_back(make_pair(15, 20));
	dates.push_back(make_pair(21,39));
	vector<vector<pair<int, int> > > result = MeetingRooms(dates);
	for (const auto& r : result) {
		for (const auto& p : r) {
			cout << p.first << "," << p.second;
		}
		cout << endl;
	}
	return 0;
}