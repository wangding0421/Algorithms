#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

bool dfs(unordered_map<char, unordered_set<char> >& g, vector<bool>& visited, vector<bool>& circle, char c) {
    if (circle[c - 'A']) return false;
    if (visited[c - 'A']) return true;

    circle[c - 'A'] = true;
    visited[c - 'A'] = true;

    for (auto it = g[c].begin(); it != g[c].end(); ++it) {
        if (!dfs(g, visited, circle, *it)) return false;
    }

    circle[c - 'A'] = false;
    return true;

}

bool topsort(unordered_map<char, unordered_set<char> >& g) {
    vector<bool> visited(26, false);
    vector<bool> circle(26, false);

    for (auto it = g.begin(); it != g.end(); ++it) {
        if (!dfs(g, visited, circle, it->first)) return false;
    }

    return true;
}

bool TaskValid(const vector<pair<char, char> >& rules) {
    unordered_map<char, unordered_set<char> > g; // graph
    for (int i = 0; i < (int) rules.size(); ++i) {
        g[rules[i].first].insert(rules[i].second);
    }

    return topsort(g);
}

int main() {
    vector<pair<char, char> > rules = {{'A', 'B'}, {'A', 'C'}, {'A', 'D'}, {'B', 'D'}, {'E', 'F'}};
    cout << TaskValid(rules) << endl;
    return 0;
}
