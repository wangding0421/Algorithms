#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
  bool validTree(int n, vector< pair<int, int> >& edges) {
    int E = edges.size();
    if (n - 1 != E) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      father.push_back(i);
      rank.push_back(0);
    }
    for (int i = 0; i < E; i++) {
      if (find(edges[i].first) == find(edges[i].second)){
        return false;
      }
      _union(edges[i].first, edges[i].second);
    }
    return true;
  }

private:
  vector<int> father;
  vector<int> rank; //Rank as the height of the tree
  int find(int node){
    if (node != father[node]) {
      /*
        Here below need to reset the father of the node
        Because after an union call the father of a node may need to be changed
       */
      father[node] = find(father[node]);
    }
    return father[node];
  }

  void _union(int node1, int node2){
    int px = find(node1);
    int py = find(node2);
    if (px == py) {
      return;
    }
    if (rank[px] > rank[py]) {
      father[py] = px;
    }
    else {
      father[px] = py;
    }
    if (rank[px] == rank[py]) {
      rank[py]++;
    }
    //father[find(node1)] = find(node2);
  }

};

int main()
{
  Solution s;
  vector< pair<int, int> > edges;
  edges.push_back(pair<int, int>(0,1));
  edges.push_back(pair<int, int>(1,2));
  edges.push_back(pair<int, int>(0,3));
  edges.push_back(pair<int, int>(2,3));
  cout << s.validTree(4, edges) << endl;
}

