// Link : https://leetcode.com/problems/is-graph-bipartite/description/
// Link : https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color){
        if(color[node] == -1){
            color[node] = 0;
        }    
        for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfs(it, graph, color) == false){
                    return false;
                }
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;   
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        
        for(int i=0; i<v; i++){
            if(color[i] == -1 && dfs(i, graph, color) == false){
                return false;
            }
        }
        return true;
    }
};