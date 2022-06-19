// Link : 


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