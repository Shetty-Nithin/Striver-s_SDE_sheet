// Link : https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581
// Link : https://www.interviewbit.com/problems/nearest-smaller-element/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// approach 1:
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> st;
    vector<int> ans(n);
    
    st.push(-1);
    for(int i=n-1; i>=0; --i){
        if(st.top() < arr[i]){
            ans[i] = st.top();
            st.push(arr[i]);
        }else{
            while(st.top() >= arr[i]){
                st.pop();
            }
            if(st.top() < arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return ans;
}


// approach 2:
vector<int> nextSmallerElement(vector<int> &arr, int n){
   	stack<int> stk;
    stk.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(stk.top() >= curr){
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(curr);
    }
    return ans;
}

// approach 3:
// Interview Bit slightly different problem
vector<int> prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    
    st.push(-1);
    for(int i=0; i<n; i++){
        if(st.top() < arr[i]){
            ans[i] = st.top();
            st.push(arr[i]);
        }else{
            while(st.top() >= arr[i]){
                st.pop();
            }
            if(st.top() < arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return ans;
}