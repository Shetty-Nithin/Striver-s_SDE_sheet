// Link : https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// approach 1 : Brute Force
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long getInversions(long long *arr, int n){
    
    long long count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

// approach 2 : Optimized