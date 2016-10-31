#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>
#include <utility>
#include <set>
#include <queue>
#include <math.h>
using namespace std;

class FriendList{
public:
	string ToString() {
		string result = "";
		for (auto it = friends.begin(); it != friends.end(); ++it) {
			result += *it;
		}
		return result;
	}
	
	void Toggle(char f) {
		if (Contains(f)) {
			friends.erase(friend_map[f]);
			friend_map.erase(f);
		} else {
			friends.push_back(f);
			auto it = friends.end();
			it--;
			friend_map[f] = it;
		}
	}

	bool Contains(char f) {
		return friend_map.count(f) > 0;
	}

private:
	list<char> friends;
	unordered_map<char, list<char>::iterator> friend_map;
};

int main() {
	FriendList f;
	f.Toggle('a');
	f.Toggle('b');
	f.Toggle('c');
	cout << f.ToString() << endl;
	f.Toggle('b');
	cout << f.ToString() << endl;
	f.Toggle('b');

	cout << f.ToString() << endl;
	f.Toggle('d');
	
	cout << f.ToString() << endl;
	return 0;
}
