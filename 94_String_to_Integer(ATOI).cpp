// Link : https://leetcode.com/problems/string-to-integer-atoi/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        long sign = 1;
                    
        int index = s.find_first_not_of(' ');
        if(index == -1) return 0;
        
        if(s[index] == '-' || s[index] == '+'){
            if(s[index++] == '-') sign = -1;
        }

        while(index < s.length() && isdigit(s[index])){
            ans = ans*10 + (s[index++]-'0');
            if(sign*ans <= INT_MIN) return INT_MIN;
            if(sign*ans >= INT_MAX) return INT_MAX;
        }
        return sign*ans;
    }
};


// Coding Ninjas
#include<string>
#include<climits>

int atoi(string s) {
    long ans = 0;
    long sign = 1;

    int index = s.find_first_not_of(' ');
    if(index == -1) return 0;

    if(s[index] == '-' || s[index] == '+'){
        if(s[index++] == '-') sign = -1;
    }

    for(int i=index; i<s.length(); i++){
        if(!isdigit(s[i])) continue;
        
        ans = ans*10 + (s[i]-'0');
        if(sign*ans <= INT_MIN) return INT_MIN;
        if(sign*ans >= INT_MAX) return INT_MAX;
    }
    return sign*ans;
}