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
        if(n < 2){
            return n;
        }
        
        int left = 0;
        int right = 1;
        
        while(right < n){
            if(nums[right] == nums[left]){
                right++;
            }else{
                left++;
                swap(nums[left], nums[right]);
                right++;
            }
        }
        
        return left+1;
    }
};