// Link : https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

// Brute Force : TLE
bool isPalindrome(string str){
    int left = 0;
    int right = str.length()-1;
    
    while(left <= right){
        if(str[left++] != str[right--]){
            return false;
        }
    }
    return true;
}

int minCharsforPalindrome(string str) {
    int count = 0;
    
    while(!isPalindrome(str)){        
        count++;
        str = str.substr(0, str.length()-1);
    }
    return count;
}

// BruteForce : working
int minCharsforPalindrome(string str) {    
    int left = 0;
    int right = str.length()-1;
    int minChars = 0;
    int last = 1;
    
    while(left <= right){
        if(str[left] != str[right]){
            left = -1;
            right = str.length()-last;
            last++;
            minChars++;
        }
        left++;
        right--;
    }
    return minChars;
}



// Optimized solution : KMP algorithm

void find_lps(string p, int m, vector<int> &lps){
    int prevLps = 0;
    for(int i=1; i<m; i++){
        if(p[i] == p[prevLps]){
            lps[i] = prevLps+1;
            prevLps++;
        }
        else if(prevLps == 0) lps[i] = 0;
        else{
            prevLps = lps[prevLps-1]; 
            i--;
        }
    }
}

int minCharsforPalindrome(string str) {    
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    string concatedStr = revStr + '$' + revStr;
    int m = concatedStr.length();
    vector<int> lps(m, 0);

    if(m == 0) return 0;
    find_lps(concatedStr, m, lps);
    
    return (str.length() - lps.back());
}