// Link : https://leetcode.com/problems/4sum/submissions/
// Link : 



#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int left = start;
        int right = nums.size()-1;
        
        int sum = 0;
        while(left < right){
            sum = nums[left] + nums[right];
            
            if(sum < target || (left > start && nums[left] == nums[left-1])){
                left++;
            }
            else if(sum > target || (right < nums.size()-1 && nums[right] == nums[right+1])){
                right--;
            }else{
                res.push_back({nums[left], nums[right]});
                left++;
                right--;
            }
        }
        
        return res;
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        
        if(start == nums.size()){
            return res;
        }
        
        int avg_value = target/k;
        
        if(nums[start] > avg_value || avg_value > nums.back()){
            return res;
        }
        
        if(k == 2){
            return twoSum(nums, target, start);
        }
        
        for(int i=start; i<nums.size(); i++){
            if(i == start || nums[i-1] != nums[i]){
                for(vector<int>& subset : kSum(nums, static_cast<long>(target)-nums[i], i+1, k-1)){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums, target, 0, 4);
    }
};