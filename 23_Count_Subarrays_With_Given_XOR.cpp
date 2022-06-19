// Link : https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://www.interviewbit.com/problems/subarray-with-given-xor/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// TLE
int subarraysXor(vector<int> &A, int x)
{
    int subArrays = 0;
    for(int i=0; i<A.size(); i++){
        int xorSum = 0;
        for(int j=i; j<A.size(); j++){
            xorSum = xorSum ^ A[j];
            if(xorSum == x){
                subArrays++;
            }
        }
    }
    
    return subArrays;
}

// Approach 2:
int subarraysXor(vector<int> &A, int x)
{
    int subArrays = 0;
    unordered_map<int, int> visited;
    
    int xorSum = 0;
    for(int i=0; i<A.size(); i++){
        
        xorSum ^= A[i];
        if(xorSum == x){
            subArrays++;
        }
        int q = xorSum ^ x;
        
        if(visited.find(q) != visited.end()){
            subArrays += visited[q];
        }
        
        visited[xorSum]++;
    }
    
    return subArrays;
}