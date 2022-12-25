// Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute force approach : Using Hash set data structure;

// optimal approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){ // no duplicate possible.
            return n;
        }
        
        int left = 0;
        int right = 1;
        // placing the unique value at left (using help of ahead right)
        while(right < n){
            if(nums[right] == nums[left]){ // do nothing and go for next number
                right++;
            }else{ // got unique number. Place it at left and increase both left and right
                left++;
                swap(nums[left], nums[right]);
                right++;
            }
        }
        
        return left+1;
    }
};