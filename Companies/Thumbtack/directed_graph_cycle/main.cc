#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

bool dfs(unordered_map<char, unordered_set<char> >& g, vector<bool>& visited, vector<bool>& circle, char c) {
    if (circle[c - 'a']) return false;
    if (visited[c - 'a']) return true;

    visited[c - 'a'] = true;
    circle[c - 'a'] = true;
    for (auto it = g[c].begin(); it != g[c].end(); ++it) {
        if (!dfs(g, visited, circle, *it)) return false;
    }
    circle[c - 'a'] = false;
    return true;
}

bool NoCycle(unordered_map<char, unordered_set<char> >& g) {
    vector<bool> visited(26, false);
    vector<bool> circle(26, false);
    
    for (auto it = g.begin(); it != g.end(); ++it) {
        if (!dfs(g, visited, circle, it->first)) return false;
    }

    return true;
}

int main() {
    unordered_map<char, unordered_set<char>> g;
    g['a'].insert('b');
    g['a'].insert('c');
    g['b'].insert('c');
    g['c'].insert('d');

    cout << NoCycle(g) << endl;
    return 0;
}
