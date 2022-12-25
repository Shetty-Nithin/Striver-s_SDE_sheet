// Link : https://leetcode.com/problems/n-queens/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    bool isSafe(int col, int row, int n, vector<string> &board){
        // for(int j=0; j<col; j++){
        //     if(row>0 && col>0 && board[row-1][col-1] != '.') return false;
        //     if(board[j][col] != '.') return false;
        //     if(row>0 && col<n-1 && board[row-1][col+1] != '.') return false;
        // } 
        // return true;
        int x = row;
        int y = col;
        
        while (x >= 0 && y >= 0) { // diagonally left-top
            if (board[x][y] == 'Q')
              return false;
            x--;
            y--;
        }
        
        x = row;
        y = col;
        while (x >= 0) {
            if (board[x][y] == 'Q') // vertically up
              return false;
            x--;
        }

        x = row;
        y = col;
        while (x >= 0 && y < n) { // diagonally right-up
            if (board[x][y] == 'Q')
              return false;
            x--;
            y++;
        }
        // below the board[row][col] is not required since its not filled yet.

        return true;
    }
    
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
            return;
        }
        
        //DFS 
        for(int col=0; col<n; col++){
            if(isSafe(col, row, n, board)){
                board[row][col] = 'Q';
                solve(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for (int i=0; i<n; i++) {
            board[i] = s;
        }
        solve(0, n, board, ans);
        
        return ans;
    }
};