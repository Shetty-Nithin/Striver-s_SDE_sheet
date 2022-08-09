// Link : https://leetcode.com/problems/count-and-say/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

string writeAsYouSpeak(int n) 
{
    string str = "1";
    for(int i=1; i<n; i++){
        int count = 1;
        string temp = "";
        int j;
        for(j=0; j<str.length(); j++){
            if(j>0 && str[j] == str[j-1]) count++;
            if(j>0 && str[j] != str[j-1]){
                temp = temp + to_string(count) + str[j-1];
                count = 1;
            }
        } 
        temp = temp + to_string(count) + str[j-1];
        str = temp;
    }
    
    return str;
}


// Approach 2 : Recursion
class Solution {
public:
    string countAndSay(int n, string s = "1") {
        if(n==1) return s;

        int i=0, j, len = s.size();
        string res = "";

        while(i<len) {
            j=i;

            while(i<len && s[i]==s[j]) i++;
            res += to_string(i-j) + s[j];
        }

        return countAndSay(n-1, res);
    }
};