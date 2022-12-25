// Link : https://leetcode.com/problems/permutation-sequence/
// YouTube : https://www.youtube.com/watch?v=va3NEycUxsg&t=859s

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute Force : TLE
class Solution {
public: 
    void solve(string str, vector<string> &res, int index, int n){
        if(index == n){
            res.push_back(str);
            return;
        }
        
        for(int i=index; i<n; i++){
            swap(str.at(index), str.at(i));
            solve(str, res, index+1, n);
            swap(str.at(index), str.at(i));
        }
    }
    
    string getPermutation(int n, int k) {
        string str;
        for(int i=1 ;i<=n; i++){
            str.push_back('0'+ i);
        }
        
        vector<string> res;
        solve(str, res, 0, n);  
        
        sort(res.begin(), res.end());
        return res[k-1];
    }
};


// Optimised approach :
class Solution {
public:   
    string getPermutation(int n, int k) {
        int fact = 1;
        string str = "";
        for(int i=1 ;i<n; i++){
            fact = fact*i;
            str.push_back('0'+i);
        }
        str.push_back('0'+n);
        
        string ans = "";
        k = k-1;
        while(n){
            ans.push_back(str.at(k/fact));
            str.erase(k/fact, 1);
            
            k = k%fact;
            if(str.length()) fact = fact/str.length();
            n--;
        }
        
        return ans;
        
    }
};