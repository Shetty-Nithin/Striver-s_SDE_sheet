// Link : https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &num, vector<int> &ansArr, int index, int sum){
    if(index == num.size()){
        ansArr.push_back(sum);
        return;
    }
    
    solve(num, ansArr, index+1, sum+num[index]);
    solve(num, ansArr, index+1, sum);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> ansArr;
    solve(num, ansArr, 0, 0);
    sort(ansArr.begin(), ansArr.end());
    return ansArr;
}