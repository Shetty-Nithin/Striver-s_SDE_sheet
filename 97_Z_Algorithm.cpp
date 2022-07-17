// Link : https://leetcode.com/problems/implement-strstr/



#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;


// Leetcode:

class Solution {
public:
    bool check(string haystack, string needle){
        
        int n = 0;
        int h = 0;
        while(n < needle.length() && h < haystack.length()){
            if(haystack[h] != needle[n]){
                return false;
            }
            else if(n == needle.length()-1){
                return true;
            }else{
                n++;
                h++;
            }
        }
        
        return false;
    }
    

    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        
        for(int h=0; h<haystack.length(); h++){
            if(haystack[h] == needle[0]){
                bool found = check(haystack.substr(h, haystack.length()), needle);
                
                if(found){
                    return h;
                }
            }
        }
        
        return -1;
    }
};



// Coding Ninjas : Z_Algorithm

// Brute Force : TLE
bool check(string haystack, string needle){
    int n = 0;
    int h = 0;
    while(n < needle.length() && h < haystack.length()){
        if(haystack[h] != needle[n]){
            return false;
        }
        else if(n == needle.length()-1){
            return true;
        }else{
            n++;
            h++;
        }
    }

    return false;
}

int strstr(string haystack, string needle, int h, int n)
{
    int occurence = 0;
    if(h < n) return occurence;

    for(int i=0; i<haystack.length(); i++){
        if(haystack[i] == needle[0]){
            bool found = check(haystack.substr(i, haystack.length()), needle);

            if(found){
                occurence++;
                haystack = haystack.substr(i+1, haystack.length());
                i = -1;
            }
        }
    }

    return occurence;
}

// another TLE : with Z-array
int zAlgorithm(string haystack, string needle, int h, int n)
{
    string totalStr = needle + '$' + haystack;
    vector<int> z;
    
    z.push_back(0);
    int i = 0;
    int match = 0;
    for(int j=1; j<totalStr.length(); j++){
        while(totalStr[j] == totalStr[i]){
            i++;
            j++;
            match++;
        }
        if(match != 0){
            j = j-match;
        }
        z.push_back(match);
        match = 0;
        i = 0;
    }
    
    match = 0;
    for(int i=n; i<z.size(); i++){
        if(z[i] == n){
            match++;
        }
    }
    
    return match;
}


// Optimized : Z_Algorithm

int zAlgorithm(string haystack, string needle, int h, int n)
{
    int occurence = 0;
    for(int i=0; i<=(h-n); i++){
        if(haystack.substr(i, n) == needle){
            occurence++;
        }
    }
    
    return occurence;
}



// Z_Alogirthm : 

int zAlgorithm(string haystack, string needle, int h, int n)
{     
    string totalStr = needle + '$' + haystack;
    int len = totalStr.length();
    vector<int> z(len);
    
    z.push_back(0);
    int l = 0;
    int r = 0;
    for(int k=1; k<len; k++){
        if(k > r){
            l=r=k;
            while(r < len && totalStr[r] == totalStr[r-l]){
                r++;
            }
            z[k] = r-l;
            r--;
        }
        else{ // k < r
            if((k+z[k-l]) <= r){
                z[k] = z[k-l];
            }
            else{
                l=k;
                while(r < len && totalStr[r] == totalStr[r-l]){
                    r++;
                }
                z[k] = r-l;
                r--;
            }
        }
    }
    
    int occurence = 0;
    for(int k=n; k<z.size(); k++){
        if(z[k] == n){
            occurence++;
        }
    }
    return occurence;
}