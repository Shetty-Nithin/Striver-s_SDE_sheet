// Link : https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


bool knows(int a, int b){
    return true;
    return false;
}
int findCelebrity(int n) {
 	stack<int> s;
    for(int i=0; i<n; i++) s.push(i);
    
    while(!s.empty() && s.size() > 1){
        int top1 = s.top();
        s.pop();
        int top2 = s.top();
        s.pop();
        
        if(knows(top1, top2)){
            s.push(top2);
        }else if(knows(top2, top1)){
            s.push(top1);
        }
    }
    
    if(!s.empty()){
        int topVal = s.top();
        int count = 0;
        for(int i=0; i<n; i++){ // check for celebrity row  it should be 0 
            if(knows(topVal, i)) return -1;
        }
        
        for(int i=0; i<n; i++){ // check for celebrity col
            if(knows(i, topVal)){
                count++;
            }
        } 
        
        if(count >= 1) return topVal;
    }
    
    return -1;
}