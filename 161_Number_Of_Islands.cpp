// Link : https://leetcode.com/problems/number-of-islands/description/
// Link : https://www.codingninjas.com/codestudio/problems/630512?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void addTo_adjList(unordered_map<int, list<int>> &adjList, vector<vector<char>> &grid, int row, int col, int i, int j, int u){
        int v;
        adjList[u];

        if(j-1 >= 0 && grid[i][j-1] == '1'){ // left
            v = col*i + (j-1); 
            adjList[u].push_back(v);
        }
        if(j+1 < col && grid[i][j+1] == '1'){ // right
            v = col*i + (j+1);
            adjList[u].push_back(v);
        }
        if(i-1 >= 0 && grid[i-1][j] == '1'){ // up
            v = col*(i-1) + j;
            adjList[u].push_back(v);
        }
        if(i+1 < row && grid[i+1][j] == '1'){ // down
            v = col*(i+1) + j;
            adjList[u].push_back(v);
        }

        /* for diagonals

        if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == '1'){ // left-top
            v = col*(i-1) + (j-1); 
            adjList[u].push_back(v);
        }
        if(i-1 >= 0 && j+1 < col && grid[i-1][j+1] == '1'){ // right-top
            v = col*(i-1) + (j+1);
            adjList[u].push_back(v);
        }
        if(i+1 < row && j-1 >= 0 && grid[i+1][j-1] == '1'){ // left-bottom
            v = col*(i+1) + (j-1);
            adjList[u].push_back(v);
        }
        if(i+1 < row && j+1 < col && grid[i+1][j] == '1'){ // right-bottom
            v = col*(i+1) + (j+1);
            adjList[u].push_back(v);
        }
        */
    }

    void dfs(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList){
        visited[i] = true;
        for(auto nbr : adjList[i]){
            if(!visited[nbr]){
                dfs(nbr, visited, adjList);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_map<int, list<int>> adjList;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            int u;
            for(int j=0; j<col; j++){
                u = col*i + j;
                if(grid[i][j] == '1'){
                    addTo_adjList(adjList, grid, row, col, i, j, u);
                }
            }
        }

        int isLands = 0;
        unordered_map<int, bool> visited;
        for(auto i : adjList){
            if(!visited[i.first]){
                isLands++;
                dfs(i.first, visited, adjList);
            }
        }
        
        return isLands;
    }
};


// Approach 2 : Coding ninja 
#include <vector>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
    dx[] and dy[] are the arrays that define each of the eight directions.

    dx[0], dy[0] : West
    dx[1], dy[1] : North-West
    dx[2], dy[2] : North
    dx[3], dy[3] : North-East
    dx[4], dy[4] : East
    dx[5], dy[5] : South-East
    dx[6], dy[6] : South
    dx[7], dy[7] : South-West

*/

vector<vector<bool>> vis;

void getTotalIslandsHelper(int** mat, int n, int m, int x, int y){
    if(!(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y])){
        return;
    }

    vis[x][y] = true;

    for(int i=0; i<8; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        getTotalIslandsHelper(mat, n, m, nextX, nextY);
    }
}

int getTotalIslands(int** mat, int n, int m){
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int islands = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1 && !vis[i][j]){
                islands++;
                getTotalIslandsHelper(mat, n, m, i, j);
            }
        }
    }

    return islands;
}


// Approach 3 : using BFS
class Solution {
private:
    void bfs(int currRow, int currCol, vector<vector<int>> &visited, vector<vector<char>> &grid, int rows, int cols){
        visited[currRow][currCol] = 1;
        queue<pair<int, int>> q;
        q.push({currRow, currCol});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second; 
            q.pop();

            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    int nrow = row + delRow;
                    int ncol = col + delCol;
                    if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int isLands = 0;
        for(int currRow = 0; currRow < rows; currRow++){
            for(int currCol = 0; currCol < cols; currCol++){
                if(!visited[currRow][currCol]){
                    isLands++;
                    bfs(currRow, currCol, visited, grid, rows, cols);
                }
            }
        }
        
        return isLands;
    }
};