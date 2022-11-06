// Link : https://leetcode.com/problems/course-schedule/description/
// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
// Link : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Kahn's Algorithm
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        
        adjList[u].push_back(v);
    }
    
    // Find all indegrees
    vector<int> inDegree(n);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // Push '0' inDegree to the queue
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    // BFS
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        count++;
        
        for(auto neighbour: adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(count == n){ // This is the condition for topological sort.
        return false; // In topological sort cycle will not be present.
    }else{
        return true; // This is invalid topological sort because of cycle.
    }
}