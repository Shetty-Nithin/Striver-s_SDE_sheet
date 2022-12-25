// Link : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        if(n > m){
            return kthElement(arr2, arr1, m, n, k); // making arr1 is smaller sized array
        }
        
        int low = max(0, k-m);
        int high = min(k, n);
        int mid1, mid2;
        int l1, h1, l2, h2;
        
        while(low <= high){
            mid1 = (low+high)/2;
            mid2 = k-mid1;
            
            l1 = (mid1 == 0) ? INT_MIN : arr1[mid1-1];
            h1 = (mid1 == n) ? INT_MAX : arr1[mid1];
            l2 = (mid2 == 0) ? INT_MIN : arr2[mid2-1];
            h2 = (mid2 == m) ? INT_MAX : arr2[mid2];
            
            if(l1 <= h2 && l2 <= h1){
                return max(l1, l2);
            }
            else if(l1 > h2){
                high = mid1-1;
            }else{
                low = mid1+1;
            }
        }
        return 1;
    }
};