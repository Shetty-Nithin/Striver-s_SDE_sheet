// Link : https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769

// Prerequisite : Disjoint set,  Union set & path compression

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool comp(vector<int> &a, vector<int> &b){
    return a[2] < b[2]; // a = b = {u, v, w}
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=1; i<=n; i++){
        parent[i] = i; // parent is self
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node; // base case
    }
    return parent[node] = findParent(parent, parent[node]); // path compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }else if(rank[v] < rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), comp);
    vector<int> parent(n);
    vector<int> rank(n);
    int minWeight = 0;

    makeSet(parent, rank, n);
    
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        if(u != v){ // if the parents are different, then we need to merge
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}