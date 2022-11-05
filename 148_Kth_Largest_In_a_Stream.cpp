// Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
// Link : https://www.codingninjas.com/codestudio/problems/800301?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto i : nums){
            minHeap.push(i);
            if(minHeap.size() > K){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if(minHeap.size() > K){
            minHeap.pop();
        }
        return minHeap.top();
    }
};