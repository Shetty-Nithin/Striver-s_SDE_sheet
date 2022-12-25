// Link : https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// approach 1:
class Solution {
public:
    bool isPresent(vector<int>& matrix, int target, int start, int end){ 
        while(start <= end){  
            int mid = (end-start)/2 + start;
            
            if(matrix[mid] == target){
                return true;
            }
            else if(matrix[mid] < target){
                return isPresent(matrix, target, mid+1, end);
            }
            else{
                return isPresent(matrix, target, start, mid-1);
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i<rows; i++){
            if(matrix[i][cols-1] >= target){
                return isPresent(matrix[i], target, 0, cols-1);
            }
        }
        
        return false;
    }
};

// approach 2:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = row*col -1;
        int mid = start + (end - start)/2;
        
        while(start <= end){
            int midNum = matrix[mid/col][mid%col];
            
            if(midNum == target) return true;
            else if(midNum > target){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            mid = start + (end - start)/2;
        }
        return false;
    }
};