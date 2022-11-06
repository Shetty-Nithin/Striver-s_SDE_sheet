// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Link : https://www.codingninjas.com/codestudio/problem-details/cycle-detection-in-undirected-graph_1062670


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited){
    unordered_map<int, int> parent;
    parent[node] = -1;
    visited[node] = true;
    
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        for(auto nbr : adjList[frontNode]){
            if(visited[nbr] && nbr != parent[frontNode]){
                return true;
            }else if(!visited[nbr]){
                parent[nbr] = frontNode;
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool ans = bfs(i, adjList, visited);
            if(ans) return "Yes";
        }
    }
    return "No";
}

