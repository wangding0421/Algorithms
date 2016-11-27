#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// MR and Highest
class WeatherUpdate{
public: 
    void Update(int time, int value) {
        if (time >= mr_time_temp_.first && value != INT_MIN) {
            mr_time_temp_.first = time;
            mr_time_temp_.second = value;
        }
        if (value > hightest_time_temp_.second) {
            hightest_time_temp_.first = time;
            hightest_time_temp_.second = value;
        }
        if (time_value_map_.count(time) && value == INT_MIN) {
            int current_max = INT_MIN;
            int recent_time = INT_MIN;
            for (const auto& p : time_value_map_) {
                int prev_max = current_max;
                if (p.first > recent_time && p.second != INT_MIN) {
                    recent_time = p.first;
                }
                current_max = max(current_max, p.second);
                if (prev_max != current_max) {
                    hightest_time_temp_.first = p.first;
                    hightest_time_temp_.second = p.second;
                }
            }
            mr_time_temp_ = make_pair(recent_time, time_value_map_[recent_time]);
        }
        time_value_map_[time] = value;
    }

    pair<int, int> GetWeatherData() {
        return make_pair(mr_time_temp_.second, hightest_time_temp_.second);
    }
    
private:
    unordered_map<int, int> time_value_map_;
    pair<int, int> mr_time_temp_ = {INT_MIN, INT_MIN};
    pair<int, int> hightest_time_temp_ = {INT_MIN, INT_MIN};
};



