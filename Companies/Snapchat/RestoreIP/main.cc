#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(const string& s, vector<string>& result, string ip, int start, int step) {
    int n = s.size();
    if (start == n && step == 4) {
        ip.resize(ip.size() - 1);
        result.push_back(ip);
        return;
    }
    if (((n - start) > (4 - step) * 3) || ((n - start) < (4 - step))) return;
    int num = 0;
    for (int i = start; i < start + 3; ++i) {
        num += num * 10 + s[i] - '0';
        if (num <= 255) {
            ip += s[i];
            dfs(s, result, ip + '.', i + 1, step + 1);
        }
        if (num == 0) break;
    }
    return;
}

vector<string> RestoreIpAddress(const string& s) {
    vector<string> result;
    string ip;
    dfs(s, result, ip, 0, 0);
    return result;
}

int main() {
    string input = "125001";
    vector<string> result = RestoreIpAddress(input);
    for (const auto& s : result) {
        cout << s << endl;
    }
}
