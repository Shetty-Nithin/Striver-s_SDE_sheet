// Link : https://www.interviewbit.com/problems/distinct-numbers-in-window/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Approach 1 : TLE
vector<int> dNums(vector<int> &A, int B) {
    vector<int> ans;
    int size = A.size();
    
    if(B > size) return ans;
    
    for(int i=0; i<=size-B; i++){
        set<int> st;
        for(int j=i; j<i+B; j++){
            st.insert(A[j]);
        }
        ans.push_back(st.size());
    }
    
    return ans;
}


// Approach 2 :  Using unordered_map
vector<int> dNums(vector<int> &A, int B) {
    vector<int> ans;
    int size = A.size();
    
    if(B > size){
        return ans;
    }
    else{
        unordered_map<int, int> count;
        
        for(int i=0; i<B; i++){
            count[A[i]]++;
        }
        ans.push_back(count.size());
        
        for(int i=1; i<=size-B; i++){
            count[A[i-1]]--;
            if(count[A[i-1]] == 0){
                count.erase(A[i-1]);
            }
            
            count[A[i+B-1]]++;
            ans.push_back(count.size());
        }
        
        return ans;
    }
}