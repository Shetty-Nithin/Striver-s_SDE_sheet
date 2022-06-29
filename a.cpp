

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<algorithm>

void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
    if (ds.size() == nums.size()) {
        ans.push_back(ds);
        for(int i=0; i<ds.size(); i++){
            cout << ds[i] << " ";
        }
        cout << endl; 
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
    if (!freq[i]) {
        ds.push_back(nums[i]);
        freq[i] = 1;
        recurPermute(ds, nums, ans, freq);
        freq[i] = 0;
        ds.pop_back();
    }
    }
}

vector < vector < int >> permute(vector < int > & nums) {
    vector < vector < int >> ans;
    vector < int > ds;
    int freq[3];
    for (int i = 0; i < nums.size(); i++) freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}

int main()
{
    vector<int> v{1, 2, 3};

    permute(v);
}