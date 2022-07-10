// Link : https://leetcode.com/problems/min-stack/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


// O(2N)
class MinStack {
    stack< pair<int, int> > s;
public:
    
    void push(int val) {
        int mini;
        if(s.empty()){
            mini = val;
        }else{
            mini = min(s.top().second, val);
        }
        
        s.push({val, mini});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
       return s.top().first; 
    }
    
    int getMin() {
        return s.top().second;
    }
};


// O(N)
class MinStack {
    stack<long long> s;
    long long mini;
public:
    
    MinStack() {
      while (s.empty() == false) s.pop();
      mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
        if(s.empty()){
            mini = value;
            s.push(value);
        }else{
            if(value < mini){
                s.push(2*value*1LL - mini);
                mini = value;
            }else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        
        long long rmv = s.top();
        s.pop();
        
        if(rmv < mini){
            mini = 2*mini - rmv;
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        
        long long rmv = s.top();
        if(rmv < mini){
            return mini;
        }
        return rmv;
    }
    
    int getMin() {
        return mini;
    }
};