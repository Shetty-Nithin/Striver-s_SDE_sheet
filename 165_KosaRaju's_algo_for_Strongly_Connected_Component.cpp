// Link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Link : https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st,
        unordered_map<int, list<int>> &adjList){
    
    visited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            dfs(neighbour, visited, st, adjList);
        }
    }   
    st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, 
           unordered_map<int, list<int>> &transpose, vector<int> &component){
    component.push_back(node);
    visited[node] = true;
    for(auto neighbour : transpose[node]){
        if(!visited[neighbour]){
            revDFS(neighbour, visited, transpose, component);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    //topological sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, visited, st, adjList);
        }
    }
    
    //create a transpose of graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++){
        visited[i] = 0;
        for(auto neighbour : adjList[i]){
            transpose[neighbour].push_back(i);
        }
    }
    
    vector<vector<int>> ans;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        if(!visited[top]){
            vector<int> component;
            revDFS(top, visited, transpose, component);
            ans.push_back(component);
        }
    }
    
    return ans;
}

// Leetcode : Slightly different problem
class Solution {
private:
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList){
        visited[node] = true;
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfs(neighbour, visited, st, adjList);
            }
        }
        st.push(node);
    }

    void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose, int &currLen){
        currLen++;
        visited[node] = true;
        for(auto neighbour : transpose[node]){
            if(!visited[neighbour]){
                revDFS(neighbour, visited, transpose, currLen);
            }
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int v = edges.size();
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<v; i++){
            adjList[i].push_back(edges[i]);
        }

        stack<int> st;
        unordered_map<int, bool> visited;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                dfs(i, visited, st, adjList); //topological sort
            }
        }
        
        //create a transpose of graph
        unordered_map<int, list<int>> transpose;
        for(int i=0; i<v; i++){
            visited[i] = 0;
            for(auto neighbour : adjList[i]){
                transpose[neighbour].push_back(i);
            }
        }
        
        int maxLen = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited[top]){
                int currLen = 0;
                revDFS(top, visited, transpose, currLen);
                maxLen = max(maxLen, currLen);
            }
        }
        if(maxLen == 1) return -1;
        return maxLen;
    }
};