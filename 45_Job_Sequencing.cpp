// Link : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution {
    public:
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n){ 
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        sort(arr, arr + n, comparison);

        int slot[5+1]; //int slot[maxDeadline+1];
        for(int i=0; i<=maxDeadline; i++){
            slot[i] = -1;
        }
        
        int maxProfit = 0;
        int maxJobs = 0;
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead; j>0; j--){ // trying to finish the work at the last moment, to get max profit
                if(slot[j] == -1){
                    slot[j] = i;
                    maxProfit += arr[i].profit;
                    maxJobs++;
                    break; // this job is completed, and going for the next job
                }
            }
        }
        
        return {maxJobs, maxProfit};
    } 
};