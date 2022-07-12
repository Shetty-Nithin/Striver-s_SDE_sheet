// Link : https://leetcode.com/problems/roman-to-integer/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbols{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                        {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int num = 0;
        
        for(int ch=0; ch<s.length(); ch++){
            num += symbols[s[ch]];
            
            if(ch > 0 && symbols[s[ch]] > symbols[s[ch-1]]){
                num = num - (2*symbols[s[ch-1]]);
            }
        }
        
        return num;
    }
};