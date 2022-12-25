// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> u_map;
        int len = 0;
        int tempLen = 0;
        
        for(int i=0; i<s.length(); i++){
            if(u_map.find(s[i]) != u_map.end()){
                i = u_map[s[i]];
                len = max(len, tempLen);
                u_map.clear();
                tempLen = 0;
            }
            else{
                tempLen++;
                u_map.insert({s[i], i});
            }
        }
        len = max(len, tempLen);
        
        return len;
    }
};

/*
string = abcabcbb
U_map:  number      index       len      tempLen
        a           0                       1
        b           1                       2
        c           2                       3
        a                    max(0, 3)      0

        b           1                       1
        c           2                       2
        a           3                       3
        b                    max(3, 3)      0

        c           2                       1
        a           3                       1
        b           4                       3
        c                    max(3, 3)      0

        a           3                       1
        b           4                       2
        c           5                       3
        b                    max(3, 3)      0 

        c           5                       1
        b           6                       2
        b                    max(3, 2)      0

*/