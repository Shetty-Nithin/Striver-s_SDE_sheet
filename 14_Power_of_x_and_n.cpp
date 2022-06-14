// Link : https://leetcode.com/problems/powx-n/
// Link : https://www.codingninjas.com/codestudio/problems/1082146?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// approach 1:
class Solution {
public:
    double myPow(double x, int n) {
        
        int nn = n;
        if(nn < 0){
            nn = -1 * n;
        }
        
        double ans = 1.0;
        for (int i = 0; i < nn; i++) {
            ans = ans * x;
        }
      
        if(n < 0){
            return 1.0/ans;
        }
        return ans;
    }
};

// approach 2:
class Solution {
public:
    double myPow(double x, int n) {
        
        long long int nn = n;
        if(nn < 0){
            nn = -1 * nn;
        }
        
        double ans = 1.0;
        while(nn){
            if(nn%2 == 0){
                x = x*x;
                nn = nn/2;
            }else{
                ans = ans*x;
                nn--;
            }
        }
        
        if(n < 0){
            return 1.0/ans;
        }
        return ans;
    }
};


// code studio problem:
int modularExponentiation(int x, int n, int m) {
    
    long long ans = 1;
    long long xx = x;

    while(n){

        xx = xx%m;
        
        if(n%2 == 0){
            xx = xx*xx;
            n = n/2;
        }else{
            ans = (ans*xx)%m;
            n--;
        }
    }  
    return (int)(ans%m);
}