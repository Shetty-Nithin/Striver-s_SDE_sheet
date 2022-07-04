// Link : https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Link : https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    
    void addNum(int num) {
        (maxHeap.empty() || maxHeap.top() > num)
            ? maxHeap.push(num)
            : minHeap.push(num);
        
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            if(maxHeap.empty()) return 0;
            else return (maxHeap.top() + minHeap.top())/2.0;
        }else{
            if(maxHeap.size() > minHeap.size()) return maxHeap.top();
            else  return minHeap.top();
        }
    }
};