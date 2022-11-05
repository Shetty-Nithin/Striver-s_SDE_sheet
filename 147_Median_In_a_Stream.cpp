// Link : https://www.codingninjas.com/codestudio/problems/975268?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/find-median-from-data-stream/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double findMedian(priority_queue<int> maxHeap, priority_queue<int, vector<int>, greater<int>> minHeap) {
    if(maxHeap.size() == minHeap.size()){
        if(maxHeap.empty()) return 0;
        else return (maxHeap.top() + minHeap.top())/2.0;
    }else{
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        else  return minHeap.top();
    }
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        (maxHeap.empty() || maxHeap.top() > arr[i])
            ? maxHeap.push(arr[i])
            : minHeap.push(arr[i]);
        
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        double median = findMedian(maxHeap, minHeap);
        ans.push_back(floor(median));
    }
    
    return ans;
}


// Approach 2: TLE
#include <algorithm>

vector<int> findMedian(vector<int> &arr, int n){
    vector<int>store;
    vector<int> medians;
    
    for(int i = 0; i < n; i++){
        store.push_back(arr[i]);
        sort(store.begin(),store.end());
        
        int median;
        if((i+1)%2==0){ // even
            median = (store[i/2] + store[(i+1)/2])/2;
        }
        else{ // odd
            median = store[i/2];
        }
  
        medians.push_back(median); 
    }
    
    return medians;
}