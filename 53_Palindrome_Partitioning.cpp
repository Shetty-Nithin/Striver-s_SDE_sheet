// Link : https://leetcode.com/problems/palindrome-partitioning/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void solve(string s, vector<vector<string>> &res, vector<string> &temp, int index){
        if(index == s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(s, res, temp, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(s, res, temp, 0);
        
        return res;
    }
};