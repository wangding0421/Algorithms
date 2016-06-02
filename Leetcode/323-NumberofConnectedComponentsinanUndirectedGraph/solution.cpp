#include <vector>
#include <set>
#include <iostream>
using namespace std;


class Solution {
public:
  int countComponents(int n, vector<pair<int, int> >& edges) {
    for (int i = 0; i < n; i++){
      father.push_back(i);
    }
    for (int i = 0; i < (int)edges.size(); i++){
      _union(edges[i].first, edges[i].second);
    }
    set<int> fathers;
    for (int i = 0; i < n; i++){
      fathers.insert(find(i));
    }
    return fathers.size();
  }
private:
  vector<int> father;
  int find(int node){
    if (node != father[node]){
      father[node] = find(father[node]);
    }
    return father[node];
  }
  void _union(int node1, int node2){
    if (find(node1) == find(node2)) return;
    father[find(node1)] = find(node2);
  }
};

int main()
{
  Solution s;
  vector< pair<int, int> > edges;
  edges.push_back(pair<int, int>(0,1));
  edges.push_back(pair<int, int>(1,2));
  edges.push_back(pair<int, int>(0,3));
  //edges.push_back(pair<int, int>(2,3));
  cout << s.countComponents(4, edges) << endl;
}

