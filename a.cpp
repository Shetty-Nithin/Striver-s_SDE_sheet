

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

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

int main(){
    vector<int> a{2,1,1};
    maxMinWindow(a, 3);
}