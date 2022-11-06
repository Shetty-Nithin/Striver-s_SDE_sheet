// Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
// Link : https://www.codingninjas.com/codestudio/problems/topological-sort_982938

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Using Kahn's Algorithm or BFS Algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //find all indegrees
    vector<int> inDegree(v);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // push '0' inDegree
    queue<int> q;
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    // BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto neighbour: adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}