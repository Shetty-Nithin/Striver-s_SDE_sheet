

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<algorithm>

void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int index){
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(target < 0){
        temp.pop_back();
        return;
    }
    if(index == candidates.size()){
        return;
    }
    
    temp.push_back(candidates[index]);
    solve(candidates, target-candidates[index], ans, temp, index+1);
    
    temp.pop_back();
    target += candidates[index-1];
    solve(candidates, target, ans, temp, index+1);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    
    solve(candidates, target, ans, temp, 0);
    return ans;
}

int main()
{
    vector<int> v{10,1,2,7,6,1,5};

    combinationSum2(v, 8);
}