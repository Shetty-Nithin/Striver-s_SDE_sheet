// Link : https://www.interviewbit.com/problems/allocate-books/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isPossible(vector<int> &A, int B, int pages){
    int BCount = 1;
    int pageSum = 0;
    
    for(int i=0; i<A.size(); i++){
        if((pageSum + A[i]) <= pages){
            pageSum += A[i];
        }else{
            BCount++;
            if(BCount > B || A[i] > pages){
                return false;
            }
            pageSum = A[i];
        }
    }
    return true;
}

int books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    
    int start = A[0];
    int end = 0;
    int sum = 0;
    for(int i=0; i<A.size(); i++){
        end = end + A[i];
        start = min(start, A[i]);
    }
    
    int ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(isPossible(A, B, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}

// Coding Ninjas
bool isPossible(vector<int> &A, int days, long long mid){
    int daysCount = 1;
    long long int totalTime = 0;
    
    for(int i=0; i<A.size(); i++){
        if((totalTime + A[i]) <= mid){
            totalTime += A[i];
        }else{
            daysCount++;
            if(daysCount > days || A[i] > mid){
                return false;
            }
            totalTime = A[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int days, int chapters, vector<int> A) {
    if(days > A.size()) return -1;
    
    long long start = 0;
    long long end = 0;
    for(int i=0; i<chapters; i++){
        end = end + A[i];
    }
    
    long long ans = -1;
    long long mid = start + (end-start)/2;
    while(start <= end){
        if(isPossible(A, days, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}