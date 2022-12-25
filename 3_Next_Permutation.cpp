// Link : https://leetcode.com/problems/next-permutation/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, j;
        int n = nums.size();
        for(i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        
        if(i < 0){ // 5, 4, 3, 2, 1
            reverse(nums.begin(), nums.end()); // 1, 2, 3, 4, 5
        }else{ // 5, 4, 1, 2, 3   |   5, 3, 4, 2, 1
            for(j=n-1; j>i; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            swap(nums[i], nums[j]); // 5, 4, 1, 3, 2  |   5, 4, 3, 2, 1
            reverse(nums.begin()+i+1, nums.end()); // 5, 4, 1, 3, 2 | 5, 4, 1, 2, 3
        }
    }
};