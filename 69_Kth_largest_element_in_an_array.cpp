// Link : https://leetcode.com/problems/kth-largest-element-in-an-array/

// Approach 1 : Sorting all the element and find the kth element.
// Approach 2 : Store all the element in the max heap and remove k-1 element from the heap;
// Approach 3 : Quickselect algorithm 
// Approach 4 : Optimal Approach as below

#include<iostream>
#include<bits/stdc++.h>
#include<string>
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
        
        return minHeap.top();
    }
};

// Coding Ninjas : Kth smallest and largest
vector<int> kthSmallLarge(vector<int> &nums, int n, int k){
    vector<int> res(2);
    priority_queue <int> maxHeap;

    for(int i=0; i<n; i++){
        maxHeap.push(nums[i]);
    }
    int count = 1;
    for(int i=1; i<=n; i++){
        int topVal = maxHeap.top();
        if(i == k) res[1] = topVal;
        if(i == n-k+1) res[0] = topVal;
        
        maxHeap.pop();
        count++;
    }
    return res;
}