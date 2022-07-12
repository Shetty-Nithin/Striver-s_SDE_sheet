// Link : https://leetcode.com/problems/reverse-words-in-a-string/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Brute Force :

class Solution {
public:
    string reverseWords(string s) {
        stack<string> store;
        string temp = "";

        for(int i=0; i<s.length(); i++){            
            if(s[i] == ' ' || i == s.length()-1){

                if(i == s.length()-1 && s[i] != ' '){
                    temp = temp + s[i];
                }
                
                if(temp.length() != 0){
                    store.push(temp);   
                }
                temp = "";
            }
            else temp = temp + s[i];
        }

        string ans = "";
        while(store.size() > 1){
            ans = ans + store.top() + ' ';
            store.pop();
        }
        ans = ans + store.top();
        return ans;
    }
};

// Optimised Solution :

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        int left = 0;
        int right = s.length()-1;
        
        while(left <= right){
            char ch = s[left];
            
            if(ch != ' '){
                temp = temp + ch;
                if(left == right){
                    if(ans == "") ans = temp;
                    else ans = temp + ' ' + ans; 
                }
            }
            else if(ch == ' ' && temp != ""){
                
                if(ans == "") ans = temp;
                else ans = temp + ' ' + ans;   
                temp = "";
            }
            left++;
        }
        
        return ans;
    }
};


// COding Ninjas : More Optimised

string reverseString(string s){
    string ans = "";
    vector<string> store;
    int start = 0, count = 0;
    
    for(int i=0; i<s.length(); i++){
        start = i;
        if(s[i] != ' '){
            count = 0;
            while(s[i] != ' '){
                count++;
                i++;
            }
            store.push_back(s.substr(start, count));
        }
    }
    
    for(int i=store.size()-1; i>=0; i--){
        ans.append(store[i]);
        ans.append(" ");
    }
    return ans;
}