// Link : https://leetcode.com/problems/two-sum/submissions/
// Link : https://www.codingninjas.com/codestudio/problems/pair-sum_697295?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// approach 1: Naive approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size()-1;
                
        int i, j;
        for(i=0; i<nums.size(); i++){
            for(j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){ 
                    return {i, j};
                }
            }
        }
        
        return {i, j};
    }
};


// approach 2: Two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> sortedArr = nums;
        sort(sortedArr.begin(), sortedArr.end());
        
        int n = nums.size();
        vector<int> res;
        int left = 0;
        int right = n-1;
        int sum, num1, num2;
        while(left < right){
            sum = sortedArr[left] + sortedArr[right];          
            if(sum == target){
                num1 = sortedArr[left];
                num2 = sortedArr[right];
                // break;
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        
        // to get the indeces
        bool flag1 = false;
        bool flag2 = false;
        for(int i=0; i<n; i++){
            if(num1 == nums[i]){
                res.emplace_back(i);
                flag1 = true;
            }
            else if(num2 == nums[i]){
                res.emplace_back(i);
                flag2 = true;
            }
            
            if(flag1 && flag2){
                break;
            }
        }
        
        return res;
    }
};

// approach 3: Using Hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        unordered_map<int, int> u_map;
        
        for(int i=0; i<nums.size(); i++){
            if(u_map.find(target-nums[i]) != u_map.end()){
                res.emplace_back(i);
                res.emplace_back(u_map[target-nums[i]]);
                
                return res;
            }
            u_map[nums[i]] = i;
        }
        
        return res;
    }  
};

// coding ninja (slightly different problem)
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &nums, int target){
    
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j] == target){
                res.push_back({nums[i], nums[j]});
            }
        }
    }

    return res;
}