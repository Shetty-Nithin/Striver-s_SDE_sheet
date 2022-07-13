// Link : https://leetcode.com/problems/longest-common-prefix/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int right = strs[0].length()-1;
        int mid = right/2;
        char midChar;
        
        while(mid <= right){ 
            midChar = strs[0][mid];
            
            for(int i=0; i<strs.size(); i++){
                if(mid >= strs[i].length()){
                    right = mid-1;
                    mid = right/2;
                    break;
                }
                
                if(strs[i][mid] != midChar){
                    right = mid-1;
                    mid = right/2;
                    break;
                }
                
                if(i == strs.size()-1){
                    mid = mid+1;
                }
            }
        }
        
        return strs[0].substr(0, mid);
    }
};


// Optimised
#include<bits/stdc++.h>
#include<algorithm>

string longestCommonPrefix(vector<string> &strs, int n)
{
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[n-1];
    
    int i = 0;
    while(i < first.length() && i < last.length()){
        if(first[i] != last[i]){
            break;
        }
        i++;
    }
    
    return strs[0].substr(0, i);
}