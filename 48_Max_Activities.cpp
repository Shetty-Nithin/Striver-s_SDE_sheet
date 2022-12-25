// Link : https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool static comparator(pair<int, int> act1, pair<int, int> act2){
    if(act1.second < act2.second) return true;
    else if(act1.second > act2.second) return false;
    else if(act1.first < act2.first) return true; // both finish times are same, so judging based on the start time
    else return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities;
    for(int i=0; i<start.size(); i++){
        activities.push_back({start[i], finish[i]});
    }
    sort(activities.begin(), activities.end(), comparator);
    
    int maxActivities = 1;
    int limit = activities[0].second;
    for(int i=1; i<start.size(); i++){
        if(limit <= activities[i].first){
            limit = activities[i].second;
            maxActivities++;
        }
    }
    
    return maxActivities;
}