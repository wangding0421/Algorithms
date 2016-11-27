#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;


string toString(int64_t startingIP, int i) {
    stringstream ss;
    ss << startingIP;
    ss << '/';
    ss << 32 - (1 << i);
    return ss.str();
}

vector<string> GetLastPart(int64_t startingIP, int range) {
    vector<string> result;
    while (range >= 2) {
       result.push_back(toString(startingIP, 2)); 
       startingIP += 2;
       range -= 2;
    }
    if (range != 0) {
        result.push_back(toString(startingIP, 0));
    }
    return result;
}

vector<string> convert(int64_t startingIP, int range) {
    int64_t finalIP = startingIP + range;
    vector<string> result;
    int i = 0;
    while (true) {
        int currentIP = startingIP;
        while (! (currentIP & 1)) {
            currentIP = currentIP >> 1;
            i++;
        }
        if (startingIP + (1 << i) > finalIP) break;
        range -= (1 << i);
        result.push_back(toString(startingIP, i));
        startingIP += (1 << i);
    }
    vector<string> final_list = GetLastPart(startingIP, range);
    return result;
}

int main()
{
    int64_t startingIP = 1234818235;
    vector<string> result = convert(startingIP, 4);
    for (auto c : result) {
        cout << c << endl;
    }
    return 0;
}
