#include <iostream>
#include <vector>


bool CanCross(const std::vector<int>& stones) {
    int length = stones.size();
    if (length == 2) return stones[1] == 1;
    if (length < 2) {
        return true;
    }
    std::vector<std::vector<int> > can_reach(length, std::vector<int>(length, -1));
    for (int i = 0; i < length; ++i) {
       can_reach[i][i] = 0;
    }
    can_reach[0][1] = 1;
    for (int i = 1; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            int temp_unit = stones[j] - stones[i];
            for (int k = 0; k < i; ++k) {
                if (can_reach[k][i] > 0 && (can_reach[k][i] == temp_unit || can_reach[k][i] == temp_unit - 1 || can_reach[k][i] == temp_unit + 1)) {
                    can_reach[i][j] = temp_unit;
                }
            }
        }
    }

    for (int i = 1; i < length; ++i) {
        if (can_reach[i][length - 1] > 0) return true; 
    }
    return false;
}

int main()
{
    std::vector<int> stones_1 = {0,1,3,5,6,8,12,17};
    std::vector<int> stones_2 = {0,1,2,3,4,8,9,11};
    std::cout << CanCross(stones_1) << std::endl;
    std::cout << CanCross(stones_2) << std::endl;
    return 0;
}
