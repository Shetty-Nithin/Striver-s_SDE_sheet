// Link : https://leetcode.com/problems/unique-paths/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// TLE
class Solution {
public:
    
    void totalPaths(int m, int n, int i, int j, int &count){
        if(i==m-1 && j==n-1){
            count++;
            return;
        }
        
        if(i <= m-1)
            totalPaths(m, n, i+1, j, count);
        if(j <= n-1)
            totalPaths(m, n, i, j+1, count);
    }
    
    
    int uniquePaths(int m, int n) {
        
        int count = 0;
        totalPaths(m, n, 0, 0, count);
        
        return count;
    }
};


class Solution {
public:
    int totalPaths(int m, int n, int i, int j){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        
        return totalPaths(m, n, i+1, j) + totalPaths(m, n, i, j+1);
    }
    
    
    int uniquePaths(int m, int n) {  
        return totalPaths(m, n, 0, 0);
    }
};

// using DP
class Solution {
public:
    
    int totalPaths(int m, int n, int i, int j, vector<vector<int>> &dp){
        
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        dp[i][j] = totalPaths(m, n, i+1, j, dp) + totalPaths(m, n, i, j+1, dp);
        return dp[i][j];
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int toalPaths = totalPaths(m, n, 0, 0, dp);
        
        return toalPaths;
    }
};

// approach 3: Combinatorics solution
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        int N = m+n-2;
        int R = m-1;
        double res = 1;
        
        
        for(int i=1; i<=R; i++){
           res = res*(N-R+i)/i; 
        }
        
        return (int)res;
    }
};