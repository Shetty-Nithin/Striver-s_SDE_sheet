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