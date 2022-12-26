// Link : https://leetcode.com/problems/implement-queue-using-stacks/submissions/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x) {
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
        
        st1.push(x); 
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        if(st2.empty()) return -1;
        int val = st2.top();
        st2.pop();
        
        return val;
    }
    
    int peek() {
        if(st2.empty()) return -1;
        else return st2.top();
    }
    
    bool isEmpty() {
        if(st2.empty()) return true;
        return false;
    }
};


// Approach 2 : Optimized push operation
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public: 
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty()){
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        if(st2.empty()) return -1;
        else return st2.top();
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) return true;
        return false;
    }
};