// Link : https://leetcode.com/problems/rotting-oranges/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    void spread(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &visited,
                queue<pair<int, int>> &rottenOranges, int row, int col){
        if(row < m-1 && grid[row+1][col] != 0 && visited[row+1][col] == 0){
            grid[row+1][col] = 2;
            visited[row+1][col] = 1;
            rottenOranges.push({row+1, col});   
        }
        if(row > 0 && grid[row-1][col] != 0 && visited[row-1][col] == 0){
            grid[row-1][col] = 2;
            visited[row-1][col] = 1;
            rottenOranges.push({row-1, col});
        }
        if(col < n-1 && grid[row][col+1] != 0 && visited[row][col+1] == 0){
            grid[row][col+1] = 2;
            visited[row][col+1] = 1;
            rottenOranges.push({row, col+1});
        }
        if(col > 0 && grid[row][col-1] != 0 && visited[row][col-1] == 0){
            grid[row][col-1] = 2;
            visited[row][col-1] = 1;
            rottenOranges.push({row, col-1});
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rottenOranges;
        int time = 0;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int freshAndRotten = 0;
        int rotten = 0;
        
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1 || grid[row][col] == 2) freshAndRotten++;
                if(grid[row][col] == 2){
                    rottenOranges.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
        rottenOranges.push({-1, -1});
        
        if(rottenOranges.size() == 0) return -1;
        else{
            while(rottenOranges.size()){
                pair<int, int> curr = rottenOranges.front();
                rottenOranges.pop();
                
                if(curr.first == -1){
                    if(!rottenOranges.empty()){
                        time++;
                        rottenOranges.push({-1, -1});
                    }
                }else{
                    rotten++;
                    spread(grid, m, n, visited, rottenOranges, curr.first, curr.second);
                }
            }
        }
        
        if(freshAndRotten == rotten) return time;
        return -1;
    }
};