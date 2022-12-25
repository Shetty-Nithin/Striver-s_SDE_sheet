// Link : https://leetcode.com/problems/merge-sorted-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k=0; // first element of nums2
    for(int i=0; i<n; i++){ // run through all the elements of the nums2
        int currNums1 = m+i-1;
        for(int j=i; j<=currNums1; j++){ // starts from i because, 0 to i-1 are already merged into nums1 array.
            if(nums1[j] <= nums2[k]){
                continue;
            }else{
                swap(nums1[j], nums2[k]);
            }
        }
        currNums1++;
        nums1[currNums1] = nums2[k];
        k++; // next element of nums2 for comparision
    }
}

int main(){
    vector<int> nums1{1,2,5,6,0,0};
    vector<int> nums2{3,4};

    merge(nums1, 4, nums2, 2);

    for(int i=0; i<6; i++){
        cout << nums1[i] << " ";
    }
}