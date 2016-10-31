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
// test
class TrieNode{
public:
	TrieNode() {
		is_word = false;
		for (int i = 0; i < 26; ++i) {
			next.push_back(nullptr);
		}
	}

	bool is_word;
	vector<TrieNode*> next;
};

class Trie{
public:
	Trie() {
		root = new TrieNode();
	}

	void add(const string& word) {
		auto p = root;
		for (const auto& c : word) {
			if (p->next[c - 'a'] == nullptr) {
				p->next[c - 'a'] = new TrieNode();
			}
			p = p->next[c - 'a'];
		}
		p->is_word = true;
	}

	bool find(const string& word) {
		auto p = root;
		for (const auto& c : word) {
			if (p->next[c - 'a'] == nullptr) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return p->is_word;
	}

	bool StartWidth(const string& prefix) {
		auto p = root;
		for (const auto& c : prefix) {
			if (p->next[c - 'a'] == nullptr) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return true;
	}
private:
	TrieNode* root;
};

int main() {
	Trie t;
	t.add("hello");
	t.add("test");
    
	cout << t.find("test") << endl;
	cout << t.StartWidth("he") << endl;
	cout << t.find("asdf") << t.StartWidth("as") << endl;
	return 0;
}
