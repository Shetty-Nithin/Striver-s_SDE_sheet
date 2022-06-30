// Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
// Link : https://www.codingninjas.com/codestudio/problems/758966?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution{
    private: 
    void solve(int row, int col, vector<vector<int>> &m, int n, string path, 
                vector<string> &ans, vector<vector<int>> &visited){
        
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }       
        
        // Down
        if(row < n-1 && visited[row+1][col] == 0 && m[row+1][col] == 1){
            visited[row][col] = 1;
            solve(row+1, col, m, n, path+'D', ans, visited);
            visited[row][col] = 0;
        }
        // Left
        if(col > 0 && visited[row][col-1] == 0 && m[row][col-1] == 1){
            visited[row][col] = 1;
            solve(row, col-1, m, n, path+'L', ans, visited);
            visited[row][col] = 0;
        }
        // Right
        if(col < n-1 && visited[row][col+1] == 0 && m[row][col+1] == 1){
            visited[row][col] = 1;
            solve(row, col+1, m, n, path+'R', ans, visited);
            visited[row][col] = 0;
        }
        // Up
        if(row > 0 && visited[row-1][col] == 0 && m[row-1][col] == 1){
            visited[row][col] = 1;
            solve(row-1, col, m, n, path+'U', ans, visited);
            visited[row][col] = 0;
        }
        
        return;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        if(m[0][0]){
            solve(0, 0, m, n, "", ans, visited);
        }
        
        return ans;
    }
};

int main(){
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1}, 
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    Solution s;
    s.findPath(m, 4);
}


// Coding Ninjas Problem
void solve(int row, int col, vector<vector<int>> &m, int n, 
           vector<vector<int>> &ans, vector<vector<int>> &visited){

    if(row == n-1 && col == n-1 && m[row][col] == 1){
        vector<int> path;
        visited[row][col] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                path.push_back(visited[i][j]);
            }
        } 
        ans.push_back(path);
        return;
    }       

    if(row < n && row >= 0 && col < n && col >= 0 && m[row][col] == 1 && visited[row][col] == 0){
        visited[row][col] = 1;
        
        solve(row+1, col, m, n, ans, visited);
        solve(row, col-1, m, n, ans, visited);
        solve(row, col+1, m, n, ans, visited);
        solve(row-1, col, m, n, ans, visited);
        
        visited[row][col] = 0;
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &m, int n) {
    vector<vector<int>> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if(m[0][0]){
        solve(0, 0, m, n, ans, visited);
    }
    return ans;
}