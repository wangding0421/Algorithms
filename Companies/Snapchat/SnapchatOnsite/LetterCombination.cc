#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<pair<int, int> > directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

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
    Trie(){
        root = new TrieNode();
    }

    void Add(const string& word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->next[c - 'A'] == nullptr) {
                p->next[c - 'A'] = new TrieNode();
            }
            p = p->next[c - 'A'];
        }
        p->is_word = true;
    }

    bool StartWith(const string& prefix) {
        TrieNode* p = root;
        for (auto c : prefix) {
            if (p->next[c - 'A'] == nullptr) return false;
            p = p->next[c - 'A'];
        }
        return true;
    }

    bool Find(const string& word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->next[c - 'A'] == nullptr) return false;
            p = p->next[c - 'A'];
        }
        return p->is_word;
    }
private:
    TrieNode* root;
};

void dfs(const vector<vector<char> >& grid, vector<string>& result, vector<vector<bool> >& visited, Trie t, string path, int old_i, int old_j) {
    if (t.Find(path)) {
        result.push_back(path);
    }
    
    if (!t.StartWith(path)) {
        return;
    }
    
    for (auto p : directions) {
        int i = old_i + p.first;
        int j = old_j + p.second;
        if (i >= 0  && i < (int) grid.size() && j >= 0 && j < (int) grid[0].size() && !visited[i][j]) {
            visited[i][j] = true;
            dfs(grid, result, visited, t, path + grid[i][j], i, j);
            visited[i][j] = false;
        }
    }
}

vector<string> WordCombination(const vector<vector<char> >& grid, const vector<string>& dict) {
    int m = grid.size();
    int n = grid[0].size();
    vector<string> result;
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    Trie t;
    for (const auto& s : dict) {
        t.Add(s);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string path = "";
            path += grid[i][j];
            visited[i][j] = true;
            dfs(grid, result, visited, t, path, i, j);
            visited[i][j] = false;
        }
    }

    return result;
}

int main() {
    Trie t;
    t.Add("MALT");
    t.Add("GOOG");
    t.Add("MAM");

//    cout << t.StartWith("ea") << endl;
//    cout << t.Find("hello") << endl;
//    cout << t.StartWith("w") << endl;

    vector<char> l1 = {'Y', 'K', 'D', 'U'};
    vector<char> l2 = {'A', 'N', 'L', 'P'};
    
    vector<char> l3 = {'U', 'T', 'S', 'A'};
    vector<char> l4 = {'B', 'D', 'H', 'M'};
    
    vector<vector<char>> input = {l1, l2, l3, l4};

    vector<string> dict = {"MALT"};

    vector<string> result = WordCombination(input, dict);

    for (auto s : result) {
        cout << s << endl;
    }
    return 0;
}
