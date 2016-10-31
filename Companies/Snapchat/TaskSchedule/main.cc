#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int> > g(numCourses);
        unordered_map<int, bool> in_request;
        for (int i = 0; i < prerequisites.size(); ++i) {
            in_request[prerequisites[i].first] = true;
            in_request[prerequisites[i].second] = true;
            g[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<int> request_result = topsort(g, numCourses);

        for (int i = 0; i < numCourses; ++i) {
            if (!in_request[i]) {
                request_result.push_back(i);
            }
        }
        return request_result;
    }
    
    vector<int> topsort(unordered_map<int, unordered_set<int> >& g, int numCourses) {
        vector<bool> circle(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> result;
        for (auto it = g.begin(); it != g.end(); ++it) {
            if (!dfs(g, circle, visited, result, it->first)) return vector<int>();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool dfs(unordered_map<int, unordered_set<int> >& g, vector<bool>& circle, vector<bool>& visited, vector<int>& result, int i) {
        if (circle[i]) return false;
        if (visited[i]) return true;
        
        circle[i] = true;
        visited[i] = true;
        for (auto it = g[i].begin(); it != g[i].end(); ++it) {
            if (!dfs(g, circle, visited, result, *it)) return false;
        }
        
        result.push_back(i);
        circle[i] = false;
        return true;
    }
};

int main() {
    Solution s;
    vector<pair<int, int> > p = {make_pair(1,0), make_pair(2,1), make_pair(1,2)};
    vector<int> result = s.findOrder(3, p);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}
