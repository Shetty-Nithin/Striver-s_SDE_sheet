// Link : https://leetcode.com/problems/implement-strstr/
// YouTube : https://www.youtube.com/watch?v=JoF0Z7nVSrA


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

// Brute Force : 
bool findPattern(string needle, string haystack) {
    int h = haystack.length();
    int n = needle.length();
    
    for(int i=0; i<=(h-n); i++){
        if(haystack.substr(i, n) == needle){
            return true;
        }
    }

    return false;
}


// Optimized :  KPM_Algorithm
void find_lps(string p, int m, vector<int> &lps){
    int prevLps = 0;
    for(int i=1; i<m; i++){
        if(p[i] == p[prevLps]){ // prefix == suffix of the current substring
            //lps[i] means, in the substring lps[i] length of prefix == lps[i] of suffix
            lps[i] = prevLps+1;
            prevLps++;
        }
        else{
            if(prevLps == 0){ // there is no prefix which = suffix in the current substring
                lps[i] = 0;
            }
            else{
                prevLps = lps[prevLps-1]; 
                // reducing the length of the prefix and suffix of the current 
                //substring to check LPS
                i--;
            }
        }
    }
}

bool findPattern(string p, string s)
{
    int m = p.length();
    int n = s.length();
    vector<int> lps(m, 0);
    
    if(m == 0) return false;
    find_lps(p, m, lps);
    
    int i=0;
    int j=0;
    while(i<n){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            if(j == 0) i++; 
            else j = lps[j-1];
        }
        if(j == m) return true;
    }
    
    return false;
}