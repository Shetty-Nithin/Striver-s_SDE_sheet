// Link : https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Approach 1: 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> res;
    
    for(auto v : kArrays){
        for(auto element : v){
            minHeap.push(element);
        }
    }
    
    while(minHeap.size()){
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return res;
}


// Approach 2:
class Node {
    public:
        int data;
        int row;
        int col;
    
        Node(int val, int row, int col){
            data = val;
            this->row = row;
            this->col = col;
        }
};

class compare {
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    vector<int> res;
    
    for(int i=0; i<k; i++){
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    while(minHeap.size()){
        Node* topVal = minHeap.top();
        res.push_back(topVal->data);
        minHeap.pop();
        
        int row = topVal->row;
        int col = topVal->col;
        
        if(col+1 < kArrays[row].size()){
            Node* nextNode = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(nextNode);
        }
    }
    
    return res;
}