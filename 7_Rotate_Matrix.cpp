// Link : https://leetcode.com/problems/rotate-image/
// Link : https://www.codingninjas.com/codestudio/problems/rotate-matrix_981260

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// rotate by 90 degree
/*
1 2 3     1 4 7     7 4 1
4 5 6     2 5 8     8 5 2
7 8 9     6 6 9     9 6 3
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
            
        for(int row=0; row<n; row++){
            for(int col=0; col<row; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        
        for(int row=0; row<n; row++){
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};



// clockwise rotation by one step
void rotateMatrix(vector<vector<int>> &mat, int rows, int cols)
{
    for(int x=0,y=0; x<rows/2 && y<cols/2; x++,y++){ // this loop is for number of outer boundaries
        int topLeft = mat[x][y];
        
        //left : [column will be constant]
        for(int row=x; row<rows-x-1; row++){
            mat[row][y] = mat[row+1][y];
        }
        
        //bottom : [row will be constant]
        for(int col=y; col<cols-y-1; col++){
            mat[rows-x-1][col] = mat[rows-x-1][col+1];
        }
        
        //right : [column will be constant]
        for(int row=rows-x-1; row>x; row--){
            mat[row][cols-y-1] = mat[row-1][cols-y-1];
        }
        
        //top : [row will be constant]
        for(int col=cols-y-1; col>y; col--){
            mat[x][col] = mat[x][col-1];
        }
        
        mat[x][y+1] = topLeft;
    }
}