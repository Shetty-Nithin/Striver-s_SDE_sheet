// Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Link : https://www.codingninjas.com/codestudio/problems/893030?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<k; i++){
            minHeap.push(nums[i]);
        }
        for(int i=k; i<n; i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        } 
        /*  alternative

            for(int i=k; i<n; i++){
                minHeap.push(nums[i]);
                if(minHeap.size() > k){
                    minHeap.pop();
                }
            }
        */
        
        return minHeap.top();
    }
};