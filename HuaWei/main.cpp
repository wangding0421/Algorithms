//
//  main.cpp
//  huawei
//
//  Created by Ding Wang on 16/11/2015.
//  Copyright © 2015 Ding Wang. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;



int main(){
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string word1;
        string word2;
        cin >> word1;
        cin >> word2;
        word1 += '@';
        
        int m = word1.size();
        int n = word2.size();
        int del_opt, ins_opt;
        int **f = new int* [m + 1];

        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[0][i] = i + 2;
        }
 
        for (int i = 1; i <= m; i++) {
            f[i][0] = 2;
        }
        
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++) {
                if (word1[i-1] == word2[j-1]) {
                    f[i][j] = f[i-1][j-1];
                    continue;
                }
                

                del_opt = f[i-1][j];
                for (int k = 0; k < i-1; k++) {
                    del_opt = del_opt < f[k][j] ? del_opt : f[k][j];
                }
                

                ins_opt = f[i][j-1] + 1;
                for (int k = 0; k < j-1; k++) {
                    ins_opt = ins_opt < f[i][k] + j - k ? ins_opt : f[i][k] + j - k;
                }
                
                f[i][j] = del_opt < ins_opt ? del_opt : ins_opt;
                f[i][j] += 2;
            }
        cout << f[m - 1][n] << endl;
    }
    return 0;
}




