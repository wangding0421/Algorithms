#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    vector<string> words = sentenceToVec(s);
    stringstream ss;
    for (int i = 0; i < (int)words.size() / 2; i++){
      swap(words[i], words[words.size() - i - 1]);
      ss << words[i] << ' ';
    }
    for (int i = words.size() / 2; i < (int) words.size(); i++){
      ss << words[i] << ' ';
    }
    s = ss.str();
    s = s.substr(0, s.size() - 1);
  }
private:
  vector<string> sentenceToVec(string &s){
    vector<string> result;
    int len = s.size();
    if (!len) return result;
    string currentWord;
    for (int i = 0; i < len; i++){
      if (s[i] == ' '){
        if (currentWord != ""){
          result.push_back(currentWord);
          currentWord = "";
        }
        continue;
      }
      else{
        currentWord += s[i];
      }
    }
    if (currentWord != "") result.push_back(currentWord);
    return result;
  }
};

int main()
{
  string ss = "1 hello word";
  Solution s;
  s.reverseWords(ss);
  cout << ss;
  return 0;
}
