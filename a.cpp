

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<algorithm>

void solve(int index, vector <int> & arr, int n, vector<vector<int>> &ans, vector<int> temp) {
    if (index == n) {
        for(int i=0; i<temp.size(); i++){
            cout << temp[i] << " ";
        }
        cout << endl;
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(arr[index]);
    solve(index+1, arr, n, ans, temp);
    temp.pop_back();
    solve(index+1, arr, n, ans, temp);
}
vector<vector<int>> subsetSums(vector < int > arr, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, arr, n, ans, temp);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    vector<int> v{1, 2, 3};

    subsetSums(v, v.size());
}