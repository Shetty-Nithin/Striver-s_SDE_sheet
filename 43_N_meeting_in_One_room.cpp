// Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{ 
    public:
    bool static comparator(pair<int, int> schedule_1, pair<int, int> schedule_2){
        if(schedule_1.second < schedule_2.second){
            return true;
        }
        return false;
    } 

    int maxMeetings(int s[], int e[], int n)
    {
        vector<pair<int, int>> scheduleArr;
        
        for(int i=0; i<n; i++){
            scheduleArr.push_back({s[i], e[i]});
        }
        
        sort(scheduleArr.begin(), scheduleArr.end(), comparator);
        
        int count = 0;
        int limit = scheduleArr[0].second;
        count++;
        
        for(int i=1; i<n; i++){
            if(scheduleArr[i].first > limit){
                limit = scheduleArr[i].second;
                count++;
            }
        }
        
        return count;
    }
};



// approach 2 : From coding ninjas
#include<algorithm>

class MeetingDetails{
    public:
    int start;
    int end;
    int pos;
};

bool comparator(MeetingDetails schedule_1, MeetingDetails schedule_2){
    if(schedule_1.end < schedule_2.end){
        return true;
    }else if(schedule_1.end > schedule_2.end){
        return false;
    }else if(schedule_1.pos < schedule_2.pos){
        return true;
    }
    return false;
} 

vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    int n = s.size();
    MeetingDetails scheduleArr[7]; // n=7
    for(int i=0; i<n; i++){
        scheduleArr[i].start = s[i];
        scheduleArr[i].end = e[i];
        scheduleArr[i].pos = i+1;
    }
    
    sort(scheduleArr, scheduleArr+n, comparator);
    
    vector<int> res;
    int limit = scheduleArr[0].end;
    res.push_back(scheduleArr[0].pos);
    
    for(int i=1; i<n; i++){
        if(scheduleArr[i].start > limit){
            limit = scheduleArr[i].end;
            res.push_back(scheduleArr[i].pos);
        }
    }
    
    return res;
}