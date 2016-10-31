#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool MyGreater(const pair<char, int>& first, const pair<char, int>& second) {
    return first.second >= second.second;
}

string EncodeString(const string& s) {
    int n = s.size();
    string result = "";
    if (n == 0) return result;
    unordered_map<char, int> char_count_map;

    // Count the number of appearance of each char
    for (const auto c : s) {
        char_count_map[c]++;
    }

    vector<pair<char, int> > char_count_arr;
    //Store these char_count pairs into vector and sorted
    for (const auto p : char_count_map) {
        char_count_arr.push_back(p);
    }
    sort(char_count_arr.begin(), char_count_arr.end(), MyGreater);

    unordered_map<char, string> char_encode_map;
    string current_encode = "1";
    //Map each char with there encoded result;
    for (const auto& p : char_count_arr) {
        char_encode_map[p.first] = current_encode;
        current_encode.insert(current_encode.begin(), '0');
    }

    // Encode the origin string
    for (const auto c : s) {
        result += char_encode_map[c];
    }

    return result;
}

int main() {
    string input = "abbcbbaca";
    // a : 01
    // b : 1
    // c : 001
    // 0111001110100101
    string result = EncodeString(input);
    cout << result << endl;
    return 0;
}
