#include <stack>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct LogInfo{
    string function_name_;
    bool is_start_;
    int timestamp_;
    LogInfo(string fn, bool is_start, int ts):
        function_name_(fn),
        is_start_(is_start),
        timestamp_(ts){}
};

struct LogResult{
    string function_name_;
    vector<pair<int, int> > occupied_time_periods_;
    LogResult(string fn, vector<pair<int, int> > otp):
        function_name_(fn),
        occupied_time_periods_(otp){}
};

vector<LogResult> FunctionLogging(const vector<LogInfo>& log_input) {
    vector<LogResult> result;
    int n = log_input.size();
    if (n == 0 || n % 2 != 0) return result;

    unordered_map<string, vector<pair<int, int> > > function_period_map;
    stack<string> function_stack;
    for (int i = 0; i < n; ++i) {
        if (log_input[i].is_start_) {
            if (function_stack.empty()) {

                function_period_map[log_input[i].function_name_].push_back(make_pair(log_input[i].timestamp_,-1));
            } else if (log_input[i].function_name_ != function_stack.top()) {
                function_period_map[log_input[i].function_name_].push_back(make_pair(log_input[i].timestamp_,-1));
                function_period_map[function_stack.top()].back().second = log_input[i].timestamp_;
            }
            function_stack.push(log_input[i].function_name_);
        } else {
            if (function_stack.empty() || function_stack.top() != log_input[i].function_name_) {
                return vector<LogResult>();
            } else {
                auto t = function_stack.top();
                function_stack.pop();
                if (!function_stack.empty() && t == function_stack.top()) {
                    continue;
                }
                function_period_map[log_input[i].function_name_].back().second = log_input[i].timestamp_;
                if (!function_stack.empty()) {
                    function_period_map[function_stack.top()].push_back(make_pair(log_input[i].timestamp_, -1));
                }
            }
        }
    }

    for (const auto& m : function_period_map) {
        result.push_back(LogResult(m.first, m.second));
    }

    return result;
}

int main() {
    vector<LogInfo> input;
    input.push_back(LogInfo("f1", true, 1));
    input.push_back(LogInfo("f1", true, 2));
    input.push_back(LogInfo("f2", true, 4));
    input.push_back(LogInfo("f2", false, 8));
    input.push_back(LogInfo("f1", false, 16));
    input.push_back(LogInfo("f1", false, 32));
    input.push_back(LogInfo("f3", true, 64));
    input.push_back(LogInfo("f3", false, 128));

    vector<LogResult> result = FunctionLogging(input);
    for (const auto& l : result) {
        cout << l.function_name_ << ": ";
        for (const auto& p : l.occupied_time_periods_) {
            cout << "[" << p.first << " , " << p.second << "]";
        }
        cout << endl;
    }
    return 0;
}
