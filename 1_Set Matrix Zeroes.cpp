// Link : https://leetcode.com/problems/set-matrix-zeroes/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        vector<int> arr1(rowSize, -1);
        vector<int> arr2(colSize, -1);
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(matrix[i][j] == 0){
                    arr1[i] = 0;
                    arr2[j] = 0;
                }
            }
        }
        
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(arr1[i] == 0 || arr2[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        } 
    }
};