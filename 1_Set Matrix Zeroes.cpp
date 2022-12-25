// Link : https://leetcode.com/probl bems/set-matrix-zeroes/


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

// Optimized : space - O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool isCol = false;

        for(int i=0; i<row; i++){
            if(matrix[i][0] == 0){
                isCol = true;
            }
            for(int j=1; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j=0; j<col; j++){
                matrix[0][j] = 0;
            }
        }
        if(isCol == true){
            for(int i=0; i<row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};