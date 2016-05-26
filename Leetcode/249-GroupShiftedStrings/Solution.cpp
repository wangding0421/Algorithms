#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
  vector<vector<string> > groupStrings(vector<string>& strings) {
    vector<vector<string> > result;
    int len = strings.size();
    if (!len) return result;
    for (int i = 0; i < len; i++){
      int curLen = strings[i].size();
      string curKey = "0";
      if (curLen == 1){
        stringMap[curKey].insert(strings[i]);
      }
      else{
        for (int j = 0; j < curLen - 1; j++){
          curKey += ',' + (strings[i][j+1] - strings[i][j] >= 0 ? strings[i][j+1] - strings[i][j] + 'a': strings[i][j+1] - strings[i][j] + 'a' + 26);
        }
        stringMap[curKey].insert(strings[i]);
      }
    }
    for (auto p : stringMap){
      result.push_back(vector<string>(p.second.begin(), p.second.end()));
    }
    return result;
  }
private:
  unordered_map <string, multiset<string> > stringMap;
};

int main()
{
  Solution s;
  vector<string> strings;
  strings.push_back("abc");
  strings.push_back("am");
  vector<vector<string> > result = s.groupStrings(strings);
  for (int i = 0; i < result.size(); i++){
    for (int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << endl;
    }
  }
  return 0;
}
