// Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
// Link : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

// Definition : A topological sort is a graph traversal in which each node v
//              is visited only after all its dependencies are visited.
//              And it is possible only on Directed Acyclic Graph(DAG).

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void topo_Sort(int node, vector<bool> &visited, stack<int> &stk, unordered_map<int, list<int>> &adjList){
    visited[node] = 1;
    for(auto neighbour:adjList[node]){
        if(!visited[neighbour]){
            topo_Sort(neighbour, visited, stk, adjList);   
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //cal DFS topological sort util funciton for all the components
    vector<bool> visited(v);
    stack<int> stk;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            topo_Sort(i, visited, stk, adjList);
        }
    }
    
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    
    return ans;
}
