// Link : https://leetcode.com/problems/sudoku-solver/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;


class Solution {
private: 
    bool isSafe(int row, int col, int num, vector<vector<char>> &board){
        for(int i=0; i<9; i++){
            if(board[i][col] == '0'+num) return false;
            if(board[row][i] == '0'+num) return false;
            // if(board[3*(row/3)+i/3][3*(col/3)+i%3] == '0'+num) return false;
        }
        
        //0-2, 3-5, 6-8
        int x = col - col%3;
        int y = row - row%3;
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(board[j][i] == '0'+num) return false;
            }
        } 
        
        return true;
    }
    
public:
    bool solve(vector<vector<char>> &board){   
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] == '.'){
                    for(int num=1; num<=9; num++){
                        if(isSafe(row, col, num, board)){
                            board[row][col] = '0'+num;
                            if(solve(board)){
                                return true;
                              }else{
                                board[row][col] = '.';
                             }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);
}