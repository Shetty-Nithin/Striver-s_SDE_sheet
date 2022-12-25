// Link : https://leetcode.com/problems/permutations/submissions/
// YouTube : https://www.youtube.com/watch?v=va3NEycUxsg&t=859s

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution { 
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};