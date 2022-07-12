// Link : https://leetcode.com/problems/longest-palindromic-substring/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int n = s.length();
        int palindromeLen = 0;
        
        for(int ch=0; ch<s.length();){
            int left = ch;
            int right = ch;
            
            while(left >=0 && right < n-1 && s[right] == s[right+1]) {
                right++;
            }
            ch = right+1;
            
            while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            
            int len = right-left+1;
            if(len > palindromeLen){
                start = left;
                palindromeLen = len;
            }
        }
        
        return s.substr(start, palindromeLen);
    }
};