#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class solution {
    public:
    pair<int, int> WordSearch(unordered_map<string, vector<int> >& word_map, const vector<string>& query_words) {
        int n = query_words.size();
        vector<int> appear_pos(n, -1);
        unordered_map<string, int> query_index_map;

        // initialize the index map
        for (int i = 0; i < (int) query_words.size(); ++i) {
            query_index_map[query_words[i]] = 0;
        }

        int current_length = INT_MAX;

        pair<string, int> current_small = {"", INT_MAX};
        pair<string, int> current_max = {"", INT_MIN};

        while (true) {
            for (int i = 0; i < n; ++i) {
                int current_index = word_map[query_words[i]][query_index_map[query_words[i]]]; 
                if (current_index < current_small.second) {
                    current_small.second = current_index;
                    current_small.first = query_words[i];
                }
                if (current_index > current_max.second) {
                    current_max.second = current_index;
                    current_max.first = query_words[i];
                }
                current_length = min(current_length, current_max.second - current_small.second);

                query_index_map[current_small.first]++;
                cout << query_index_map[current_small.first] << endl;
                if (query_index_map[current_small.first] >= (int) word_map[current_small.first].size()) {
                    break;
                }
            }
        }
        return make_pair(current_small.second, current_max.second);
    }
};

int main () {
    unordered_map<string, vector<int> > word_map;
    word_map["big"] = {6, 14};
    word_map["dog"] = {3, 7, 12};
    word_map["small"] = {2, 11};

    vector<string> query_words = {"big", "dog", "small"};
    solution s;

    pair<int, int> result = s.WordSearch(word_map, query_words);
    cout << result.first << "," << result.second << endl;
    return 0;
}
