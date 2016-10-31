#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(unordered_map<char, unordered_set<char> >& g, vector<bool>& circle, vector<bool>& visited, string& result, char c) {
    if (circle[c - 'a']) return false;
    if (visited[c - 'a']) return true;

    circle[c - 'a'] = true;
    visited[c - 'a'] = true;
    for (auto it = g[c].begin(); it != g[c].end(); ++it) {
        if (!dfs(g, circle, visited, result, *it)) return false; 
    }

    result += c;
    circle[c - 'a'] = false;
    return true;
}

string topsort(unordered_map<char, unordered_set<char> >& g) {
    vector<bool> circle(26, false);
    vector<bool> visited(26, false);

    string result;

    for (auto it = g.begin(); it != g.end(); ++it) {
        if (!dfs(g, circle, visited, result, it->first)) return "";
    }

    reverse(result.begin(), result.end());
    return result;
}

string alienOrder(vector<string>& words) {
    if (words.size() == 1) {
        return words.front();
    }
    unordered_map<char, unordered_set<char> > g;

    for (int i = 1; i < (int) words.size(); ++i) {
        string w1 = words[i - 1];
        string w2 = words[i];
        bool dispatched = false;
        for (int j = 0; j < std::max((int) w1.size(), (int) w2.size()); ++j) {
            if (j < (int) w1.size() && g.count(w1[j]) == 0) g.insert(make_pair(w1[j], unordered_set<char>()));
            if (j < (int) w2.size() && g.count(w2[j]) == 0) g.insert(make_pair(w2[j], unordered_set<char>()));
            if (j < (int) w1.size() && j < (int) w2.size() && w1[j] != w2[j] && !dispatched) {
                dispatched = true;
                g[w1[j]].insert(w2[j]);
            }
        }
    }
    return topsort(g);
}

int main() {
    vector<string> words = {  "wrt",
      "wrf",
      "er",
      "ett",
      "rftt"};

    cout << alienOrder(words) << endl;
}
