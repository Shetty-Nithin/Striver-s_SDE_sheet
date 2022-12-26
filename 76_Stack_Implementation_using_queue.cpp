// Link : https://leetcode.com/problems/implement-stack-using-queues/submissions/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};