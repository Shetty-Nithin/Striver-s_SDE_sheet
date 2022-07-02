// Link : https://www.interviewbit.com/problems/matrix-median/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int left = 0;
    int right = INT_MAX;
    int totalSize = A.size() * A[0].size();
    int mid;

    while(right - left > 1){
        mid = left + (right - left) / 2;
        int count = 0;
        for(auto &a: A){ 
            int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
            count += p;
        }
        if(count >= (totalSize/2 +1)){
            right = mid;
        }
        else{
            left = mid;
        }
    }   
    return right;
}


// Link :  https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<climits>
#include<algorithm>

int getMedian(vector<vector<int>> &matrix){
    int low = 0;
    int high = INT_MAX;
    int totalSize = matrix.size()*matrix[0].size();
    int mid;
    while((high-low) > 1){
        mid = low + (high-low)/2;
        int count = 0;
        for(auto m : matrix){
            int p = upper_bound(m.begin(), m.end(), mid) - m.begin();
            count += p;
        }
        
        if(count > (totalSize/2)){
            high = mid;
        }else{
            low = mid;
        }
    }
    
    return high;
}