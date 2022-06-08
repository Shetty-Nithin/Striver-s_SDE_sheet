// Link : https://leetcode.com/problems/merge-intervals/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    int size = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());
    
    for(int i=0; i<size; i++){
        if(ans.empty() || ans.back()[1] < intervals[i][0]){
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
        else{
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
    
}
