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
    
    // DFS : https://leetcode.com/problems/palindrome-partitioning/solutions/857510/palindrome-partitioning/
    void solve(string s, vector<vector<string>> &res, vector<string> &temp, int index){
        if(index == s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1)); // 0-0+1 = 1
                solve(s, res, temp, i+1); // i+1 not index+1
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

/*
                                                             aab

                                                             
                        index=0                             index=0                                 index=0
                        i=0                                 i=1                                     i=2
                        temp=["a"]                          temp=["aa"]                             temp=[]
                        res=[]                              res=[]                                  res=[]


            index=1             index=1                               index=2(i+1)
            int=1               int=2                                 int=2
            temp=["a", "a"]     temp=["a"]                            temp=["aa", "b"]
            res=[]              res=[["a","a","b"]]                   res=[["a","a","b"],
                                                                            ["aa","b"]]

    index=2
    int=2
    temp=["a", "a", "b"]
    res=[["a","a","b"]]

*/