#include <vector>
#include <iostream>
using namespace std;

class NestedInteger{
public:
    NestedInteger(int val):
        is_integer_(true),
        val_(val){}

    NestedInteger(vector<NestedInteger> list):
        is_integer_(false),
        sub_list_(list){}

    bool IsInteger() const {
        return is_integer_;
    }
    int GetInteger() const {
        if (is_integer_) {
            return val_;
        } else {
            throw "Not an integer!";
        }
    }
    vector<NestedInteger> GetList() const {
        if (is_integer_) {
            throw "Not a list!";
        } else {
            return sub_list_;
        }
    }
private:
    bool is_integer_;
    int val_;
    vector<NestedInteger> sub_list_;
};

int DepthSum(const vector<NestedInteger>& input, int current_depth) {
    int result = 0;
    current_depth++;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (input[i].IsInteger()) {
            result += current_depth * input[i].GetInteger();
        } else {
            result += DepthSum(input[i].GetList(), current_depth);
        }
    }
    current_depth--;
    return result;
}

int DepthSum(const vector<NestedInteger>& input) {
    return DepthSum(input, 0);
}

int GetMaxLevel(const vector<NestedInteger>& input) {
    if (input.empty()) return 0;
    int maxLevel = 1;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (!input[i].IsInteger()) maxLevel = max(maxLevel, GetMaxLevel(input[i].GetList()) + 1);
    }
    return maxLevel;
}

int DepthSumReverseWithLevel(const vector<NestedInteger>& input, int MaxLevel) {
    int result = 0;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (input[i].IsInteger()) {
            result += MaxLevel * input[i].GetInteger();
        } else {
            result += DepthSumReverseWithLevel(input[i].GetList(), MaxLevel - 1);
        }
    }
    return result;
}

int DepthSumReverse(const vector<NestedInteger>& input) {
    return DepthSumReverseWithLevel(input, GetMaxLevel(input));
}

int main() {
    NestedInteger n1(1);
    NestedInteger n2(4);
    NestedInteger n3(6);
    vector<NestedInteger> third_level = {n3};
    NestedInteger n4(third_level);
    vector<NestedInteger> second_level = {n2, n4}; 
    NestedInteger n5(second_level);

    vector<NestedInteger> input = {n1, n5};
    cout << DepthSum(input) << endl;
    cout << DepthSumReverse(input) << endl;

}
