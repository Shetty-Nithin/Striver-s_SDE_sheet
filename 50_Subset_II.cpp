// Link : https://leetcode.com/problems/subsets-ii/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(vector<int> &nums, set<vector<int>> &s, int index, vector<int> temp){
        if(index == nums.size()){
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(nums, s, index+1, temp);
        
        temp.pop_back();
        solve(nums, s, index+1, temp);
        
//         solve(nums, s, index+1, temp);
        
//         temp.push_back(nums[index]);
//         solve(nums, s, index+1, temp);
        
//         temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        solve(nums, s, 0, temp);
        
        vector<vector<int>> ans;
        for (auto v = s.begin(); v != s.end(); v++) {
          ans.push_back( * v);
        }
        
        return ans;
    }
};


// Approach 2 : optimal approach
class Solution {
public:
    
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int> &temp){
        ans.push_back(temp);
        
        for(int i=index; i<nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(nums, ans, i+1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, 0, temp);
        
        return ans;
    }
};