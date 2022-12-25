// Link : https://leetcode.com/problems/pascals-triangle/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascalTrngle(n, vector<int> (n));
        pascalTrngle[0].resize(1);
        pascalTrngle[0][0] = 1;

        for(int i=1; i<n; i++){
            pascalTrngle[i].resize(i+1);
            for(int j=0; j<=i; j++){
                if(j < 1 || j == i){
                    pascalTrngle[i][j] = 1;
                }else {
                    pascalTrngle[i][j] = pascalTrngle[i-1][j-1] + pascalTrngle[i-1][j];   
                }
            }
        }
        return pascalTrngle; 
    }
};

//approach 2:
vector<vector<long long int>> printPascal(int n){
    
    vector<vector<long long int>> pascalTrngle(n, vector<long long int> (n));

    for (int i=0; i<n; i++) {
        pascalTrngle[i].resize(i+1);
        pascalTrngle[i][0] = pascalTrngle[i][i] = 1;

        for (int j=1; j<i; j++){
            pascalTrngle[i][j] = pascalTrngle[i-1][j-1] + pascalTrngle[i-1][j];
        }
    }
    
    return pascalTrngle;
}