// Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Link : https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, vector<int> &component, unordered_map<int, list<int>> &adjList){
    
    component.push_back(node);
    visited[node] = true;
    
    for(auto nbr : adjList[node]){
        if(!visited[nbr]){
            dfs(nbr, visited, component, adjList);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{    
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> dfsTraversals;
    unordered_map<int, bool> visited;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, visited, component, adjList);
            dfsTraversals.push_back(component);
        }
    }
    
    return dfsTraversals;
}