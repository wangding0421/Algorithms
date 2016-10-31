#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void processSynFile(ifstream &synFile, unordered_map<string, string> &wordToSyn) {
  string line;
  while (getline(synFile, line)) {
    string key;
    istringstream strIn(line);
    strIn >> key;

    string word;
    while (strIn >> word) {
      wordToSyn[word] = key;
    }
  }
  synFile.close();
}

string joinIt(list<string> &wordsQ) {
  string res = "";
  for (auto it: wordsQ) {
    res = res + it + " ";
  }
  return res;
}

void processTwoFile(
  ifstream &twoFile, unordered_map<string, string> &wordToSyn, int tupleLen, unordered_set<string> &tuples) {
  string word;
  list<string> wordsQ;
  while (twoFile >> word) {
    if (wordToSyn.count(word)) {
      word = wordToSyn[word];
    }
    wordsQ.push_back(word);

    if (tupleLen) {
      tupleLen--;
    }

    if (!tupleLen) {
      tuples.insert(joinIt(wordsQ));
      wordsQ.pop_front();
    }
  }
  twoFile.close();
}

double processOneFile(
  ifstream &oneFile, unordered_map<string, string> &wordToSyn, int tupleLen, unordered_set<string> &tuples) {
  string word;
  list<string> wordsQ;
  int tot = 0, plag = 0;
  while (oneFile >> word) {
    if (wordToSyn.count(word)) {
      word = wordToSyn[word];
    }
    wordsQ.push_back(word);

    if (tupleLen) {
      tupleLen--;
    }

    if (!tupleLen) {
      tot++;
      string tuple = joinIt(wordsQ);
      if (tuples.count(tuple)) {
        plag++;
      }
      wordsQ.pop_front();
    }
  }
  oneFile.close();

  return tot ? double(plag) / tot : 0;
}

int main(int argc, const char * argv[]) {
  ifstream synFile;
  ifstream oneFile;
  ifstream twoFile;
  int tupleLen = 3;

  if (argc == 4) {
    synFile.open(argv[1]);
    oneFile.open(argv[2]);
    twoFile.open(argv[3]);
  } else if (argc == 5) {
    synFile.open(argv[1]);
    oneFile.open(argv[2]);
    twoFile.open(argv[3]);
    tupleLen = atoi(argv[4]);
  } else {
    cout << "Usage instructions:" << endl;
    cout << "1. File name for a list of synonyms" << endl;
    cout << "2. Input file 1" << endl;
    cout << "3. Input file 2" << endl;
    cout << "4. (optional) The number N, the tuple size. If not applied, the default N = 3" << endl;
    return 0;
  }

  unordered_map<string, string> wordToSyn;
  processSynFile(synFile, wordToSyn);

  unordered_set<string> tuples;
  processTwoFile(twoFile, wordToSyn, tupleLen, tuples);

  cout << processOneFile(oneFile, wordToSyn, tupleLen, tuples) * 100
       << "%" << endl;
  return 0;
}
