// Link : https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Brute Force : TLE

int findMax(vector<int> &a, int n, int k){
    int maxi = INT_MIN;
    deque<int> mini;
    
    for(int i=0; i<n; i++){
        if(!mini.empty() && mini.front() == i-k){
            mini.pop_front();
        }
        while(!mini.empty() && a[i] < a[mini.back()]){
            mini.pop_back();
        }
        mini.push_back(i);
        if(i >= k-1){
            maxi = max(maxi, a[mini.front()]);            
        }
    }
    return maxi;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> maxOfMins;
    for(int i=1; i<=n; i++){
        int maxi = findMax(a, n, i);
        maxOfMins.push_back(maxi);
    }
    
    return maxOfMins;
}

// Optimised

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> next(n+1);
    vector<int> prev(n+1);
    stack<int> s;
   
    for(int i=0; i<n; i++){
        next[i] = n;
        prev[i] = -1;
    }

    for(int i=0; i<n; i++){
        while(!s.empty() && a[s.top()] >= a[i]){
            s.pop();
        }

        if(!s.empty()){
            prev[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()) s.pop();

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && a[s.top()] >= a[i]){
            s.pop();
        }

        if(!s.empty()){
            next[i] = s.top();
        }
        s.push(i);
    }
    vector<int> ans(n+1);
    for(int i=0; i<=n; i++){
        ans[i] = INT_MIN;
    }

    for(int i=0; i<n; i++){
        int len = next[i] - prev[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    
    for(int i=n-1; i>=1; i--){
        ans[i] = max(ans[i], ans[i+1]);
    }
    
    vector<int> res(n);
    for(int i=1; i<=n; i++){
        res[i-1] = ans[i];
    }
    
    return res;
}