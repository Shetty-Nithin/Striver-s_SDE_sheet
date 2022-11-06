// Link : https://leetcode.com/problems/is-graph-bipartite/description/
// Link : https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int start, int v, vector<vector<int>> edges, int color[], unordered_map<int, list<int>> &adjList){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it : adjList[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;   
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    int v = edges.size();
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(edges[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
     
    // int color[v];
    int color[5];
    for(int i=0; i<v; i++){
        color[i] = -1;
    }
    
    for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(bfs(i, v, edges, color, adjList) == false){
                return false;
            }
        }
    }
    return true;
}

// Approach 2 : Leetcode
class Solution {
private:
    bool bfs(int start, int v, vector<vector<int>> &graph, vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;   
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        
        for(int i=0; i<v; i++){
            if(color[i] == -1){
                if(bfs(i, v, graph, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};