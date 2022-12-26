// Link : https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=1


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastCow = stalls[0]; // start placing the cows from first position
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i] - lastCow >= mid){ // if adequate distance is present between these 2 positions
            cowCount++;
            lastCow = stalls[i];
            if(cowCount == k) return true; // if all the cows are positioned
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size()-1];
    
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start <= end){
        if(isPossible(stalls, k, mid)){
            ans = mid;
            start = mid+1; // Becuase we need largest minimum distance
        }else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}

// Coding Ninjas Chess Tournment
bool isPossible(vector<int> &positions, int n, int c, int focus){
    int playerCount = 1;
    int lastPlayerRoom = positions[0];
    
    for(int i=0; i<n; i++){
        if(positions[i] - lastPlayerRoom >= focus){
            playerCount++;
            lastPlayerRoom = positions[i];
            if(playerCount == c) return true;
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
    
	sort(positions.begin(), positions.end());
    int start = 0;
    int end = positions[positions.size()-1];
    
    int mid;
    int focusLevel = -1;
    while(start <= end){
        mid = start + (end-start)/2;
        if(isPossible(positions, n, c, mid)){
            focusLevel = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    
    return focusLevel;
}

/*
Intuition for Binary Search : If the one particular number is not possible, then the number less/greater
                              than that number is also not possible, in this case we can apply binary search to
                              reduce the search space.
*/