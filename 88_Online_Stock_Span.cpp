// Link : https://leetcode.com/problems/online-stock-span/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;


// Using recursion : TLE

class StockSpanner {
    stack<int> s;
    vector<int> spans;
    int span;
public:
    void findSpan(int price, int &span) {
        if(s.empty() || s.top() > price){
            return;
        }
        
        span++;
        
        int backup = s.top();
        s.pop();
        findSpan(price, span);
        s.push(backup);
    }
    
    int next(int price) {
        s.push(price);
        span = 0;
        findSpan(price, span);
        return span;
    }
};



// Optimised 

class StockSpanner {
    stack<pair<int, int>> spans;
    int span;
public:
    
    int next(int price) {
        span = 1;
        
        while(!spans.empty() && spans.top().first <= price){
            span += spans.top().second;
            spans.pop();
        }
        spans.push({price, span});
        
        return span;
    }
};
