// Link : https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
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



// Interview Bit slightly different problem
// Link : https://www.interviewbit.com/problems/nearest-smaller-element/

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