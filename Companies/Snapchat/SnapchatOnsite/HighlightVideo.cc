#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// Video -> int

class Person{
public:
    Person(vector<int> v, vector<Person> f):
        videos(v),
        friends(f){}

    vector<int> videos;
    vector<Person> friends;
};

bool myCompare(const pair<int, int>& first, const pair<int, int>& second) {
    return first.second >= second.second;
}


class Solution{
public:
    void UpdateVideoCountMap(const Person& p, int remaining_level) {
        if (remaining_level == 0) {
            for (auto i : p.videos) {
                video_count_map[i]++;
            }
        } else {
            for (const auto & f : p.friends) {
                UpdateVideoCountMap(f, remaining_level - 1);
            }
            UpdateVideoCountMap(p, remaining_level - 1);
        }
    }

        // returning a list of pair: video, count in sorted
    vector<pair<int, int> > GetVideo(const Person& self, int level) {
        UpdateVideoCountMap(self, level);
        vector<pair<int, int> > result;
        for (const auto& p : video_count_map) {
           result.push_back(p);
        }
        sort(result.begin(), result.end(), myCompare);
        return result;
    }
private:
    unordered_map<int, int> video_count_map;
};

int main() {
    vector<int> f1_videos = {1,3,5};
    vector<int> f2_videos = {1,3,10};
    vector<int> self_videos = {5};
    Person f1(f1_videos, vector<Person>());
    Person f2(f2_videos, vector<Person>());
    vector<Person> f_list = {f1, f2};
    Person self(self_videos, f_list);
    
    cout << "testing" << endl;

    Solution s;
    vector<pair<int, int> > result = s.GetVideo(self, 1);
    for (const auto & p : result) {
        cout << p.first << "," << p.second << endl;
    }
    return 0;
}
