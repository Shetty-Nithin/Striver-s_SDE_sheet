// Link : https://leetcode.com/problems/sliding-window-maximum/



#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Brute Force : TLE

class Solution {
public:
    int findMax(vector<int> &nums, int start, int end){
        int maxi = INT_MIN;
        for(int i=start; i<=end; i++){
            maxi = max(maxi, nums[i]);
        }
        
        return maxi;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        int maxi = INT_MIN;
        for(int i=0; i<k; i++){
            maxi = max(maxi, nums[i]);
            
        }
        res.push_back(maxi);
        
        for(int i=k; i<nums.size(); i++){
            if(nums[i-k] != maxi){
                maxi = max(maxi, nums[i]);
            }
            else{
                maxi = findMax(nums, i-(k-1), i);
            }
            res.push_back(maxi);
        }  
        
        return res;
    }
};


// Optimised Solution :
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i >= k-1){
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};