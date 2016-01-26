//
//  main.cpp
//  MinHeap
//
//  Created by Ding Wang on 24/10/2015.
//  Copyright © 2015 Ding Wang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare{
    bool operator()(int& first, int& second){
        return first > second;
    }
};
int main(int argc, const char * argv[]) {
    priority_queue<int, vector<int>> max;
    priority_queue<int, vector<int>, greater<int>> min;
    
    
    max.push(3);
    max.push(5);
    max.push(1);
    max.push(8);
    while ( !max.empty() )
    {
        cout << max.top() << endl;
        max.pop();
    }
    // insert code here...
    return 0;
}
