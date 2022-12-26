// Link : https://leetcode.com/problems/next-greater-element-i/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//Brute Force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int ansSize = ans.size();
                if(nums1[i] == nums2[j]){
                    for(int k=j; k<nums2.size(); k++){
                        if(nums2[k] > nums1[i]){
                            ans.push_back(nums2[k]);
                            break;
                        }  
                    }
                }
                
                if(ansSize != ans.size()){
                    break; // next greater was found and pushed to the ans array at line 21
                }
                if(j == nums2.size()-1){
                    ans.push_back(-1); // next greater is not found in nums2 array.
                }
            }
        }
        return ans;
    }
};

//Using stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nextGreater(n);
        stack<int> st;
        vector<int> ans;
        
        st.push(-1);
        // for storing the next greater element in an array to avoid the 3 for loop as in the above solution
        for(int i=nums2.size()-1; i>=0; --i){
            if(st.top() > nums2[i]){
                nextGreater[i] = st.top();
                st.push(nums2[i]);
            }else{
                while(st.top() <= nums2[i]){ // pop all the element which are <= current nums2[i] element.
                    if(st.top() == -1){
                        nextGreater[i] = st.top(); // or -1
                        st.push(nums2[i]);
                        break;
                    }
                    else st.pop();
                }
                // this if is required when the greater element is found before hitting the -1 value while
                // popping using while condition
                if(st.top() > nums2[i]){
                    nextGreater[i] = st.top();
                    st.push(nums2[i]);
                }
            }
        }

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    ans.push_back(nextGreater[j]);
                    break;
                }
            }
        }
        
        return ans;
    }
};


// Coding ninjas slightly different problem
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> ans(n);
    
    st.push(-1);
    for(int i=n-1; i>=0; --i){
        if(st.top() > arr[i]){
            ans[i] = st.top();
            st.push(arr[i]);
        }else{
            while(st.top() <= arr[i]){
                if(st.top() == -1){
                    ans[i] = st.top();
                    st.push(arr[i]);
                    break;
                }
                else st.pop();
            }
            if(st.top() > arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
    }
    return ans;
}