// Link : https://leetcode.com/problems/valid-anagram/submissions/

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

// approach 1 :
bool areAnagram(string &str1, string &str2){
    map<char, int> freqStr1;
    
    for(int i=0; i<str1.length(); i++){
        freqStr1[str1[i]]++;
    }
    for(int j=0; j<str2.length(); j++){
        char ch = str2[j];
        if(freqStr1.find(ch) == freqStr1.end() || freqStr1[ch] <= 0){
            return false;
        }else{
            freqStr1[ch]--;
        }
    }
    for(auto k : freqStr1){
        if(k.second != 0) return false;
    }
    return true;
}


// approach 2 : 
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        unordered_map<char, int> freq;
        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
         
        for(auto f : freq){
            if(f.second != 0) return false;
        }
        return true;
    }
};


// approach 3 : 
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};