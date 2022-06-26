// Link : https://leetcode.com/problems/combination-sum-ii/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, temp, i+1);   
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        solve(candidates, target, ans, temp, 0);
        return ans;
    }
};