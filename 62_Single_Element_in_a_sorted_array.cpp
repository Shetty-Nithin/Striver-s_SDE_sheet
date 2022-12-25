// Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

// Brute Force Approach
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        
        return ans;
    }
};

// Optimal Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-2;
        
        int mid = 0;
        while(left <= right){
            mid = left + (right-left)/2;
            if(mid%2 == 0){ // Note 1
                if(nums[mid] != nums[mid+1]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{ // Note 2
                if(nums[mid] == nums[mid+1]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
        }
        
        return nums[left];
    }
};

/*
Note 1:
    If the mid%2 == 0 (i.e., even), then mid-1 is a differnt number and mid+1 is the same number.

Note 2:
    If the mid%2 == 1 (i.e., odd), then mid-1 is a same number and mid+1 is a different number.


XOR : 
     a  |  b  | a ^ b
    ----|-----|------
     0  |  0  |  0
     0  |  1  |  1
     1  |  0  |  1
     1  |  1  |  0
*/