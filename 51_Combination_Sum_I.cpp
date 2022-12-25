// Link : https://leetcode.com/problems/combination-sum/
// Link : https://www.codingninjas.com/codestudio/problems/759331?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(candidates, target-candidates[index], ans, temp, index);
            temp.pop_back();
        }
        solve(candidates, target, ans, temp, index+1);   
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {   
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(candidates, target, ans, temp, 0);    
        return ans;
    }
};

// Coding ninjas little different problem (because of negative numbers)
void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int index){
    if(index == candidates.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(candidates[index]);
    solve(candidates, target-candidates[index], ans, temp, index+1);
    temp.pop_back();
    solve(candidates, target, ans, temp, index+1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> candidates, int n, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    solve(candidates, target, ans, temp, 0);  
    return ans;
}