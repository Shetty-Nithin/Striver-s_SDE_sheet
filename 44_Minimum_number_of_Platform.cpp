// Link : https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400   

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach: TLE
bool static comparator(pair<int, int> n1, pair<int, int> n2){
    if(n1.second < n2.second){
        return true;
    }
    return false;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    vector<pair<int, int>> scheduleArr;
    for(int i=0; i<n; i++){
        scheduleArr.push_back({at[i], dt[i]});
    }
    sort(scheduleArr.begin(), scheduleArr.end(), comparator);
    
    int minPlatform = 1;
    int deptTime;
    for(int i=0; i<n-1; i++){
        deptTime = scheduleArr[i].second;
        int temp = 1;
        for(int j=i+1; j<n; j++){
            if(scheduleArr[j].first <= deptTime){
                temp++;
            }
        }
        minPlatform = max(minPlatform, temp);
    }
    
    return minPlatform;
}

// approach 2:
#include<algorithm>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);
    
    int minPlatform = 1;
    int temp = 1;
    int i = 0;
    int j = 1;
    while(j<n && i<n){
        if(at[j] <= dt[i]){
            temp++;
            j++;
        }else{
            temp--;
            i++;
        }
        minPlatform = max(minPlatform, temp);
    }
    
    return minPlatform;
} 