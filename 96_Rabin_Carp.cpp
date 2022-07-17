// Link : https://leetcode.com/problems/repeated-string-match/submissions/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
private:
    int BASE = 1000000;
public:
    
    int Rabin_Karp(string source, string B){
        if(source == "" or B == "") return -1;
        int m = B.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+B[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == B)
                    return i-m+1;
            }
        }
        return -1;
    }
    
    int repeatedStringMatch(string A, string B) {
        if(A == B) return 1;
        int count = 1;
        string source = A;
        
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        
        return -1;
    }
};

/*
// TLE and MLE
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int count = 1;
        string repeatedA = a;

        int compareLen = 0;
        int i = 0;
        int j = 0;
        while(j < b.length() && i < repeatedA.length()){
            if(b[j] == repeatedA[i]){
                compareLen++;
                i++;
                j++;
                
                if(repeatedA.length()-i < b.length()-j){
                    repeatedA = repeatedA + a;
                    count++;
                }
                
            }else{
                i = i-j+1;
                j = 0;
                compareLen = 0;
            }
        }

        if(compareLen == b.length()){
            return count;
        }
        return -1;
    }
};

*/