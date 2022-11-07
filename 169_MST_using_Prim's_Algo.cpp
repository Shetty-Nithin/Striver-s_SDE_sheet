// Link : https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633
// Link : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Intuition is updating minimum distance to the parent from the current node and
// creating the graph, which leads to MST.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    // (n+1) : to match node and index
    vector<int> weight(n+1); // weight[1] is the weight between 0 and 1
    vector<bool> mst(n+1); 
    vector<int> parent(n+1);
    
    for(int i=0; i<=n; i++){
        weight[i] = INT_MAX; // considering the max weight initially
        mst[i] = false; // no node is belong to MST initially
        parent[i] = -1;
    }
    weight[1] = 0;
    parent[1] = -1; //considering 1 as source node
    
    for(int i=1; i<n; i++){
        int minWeight = INT_MAX;
        int u;
        
        // finding the min weight in the weight array.
        for(int v=1; v<=n; v++){
            if(mst[v] == false && weight[v] < minWeight){
                u = v; // assigning minimum value in the weight array to "u"
                minWeight = weight[v]; // updating the minimum value
            }
        }
        mst[u] = true;
        
        for(auto neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            
            // Here it is checking which parent has the min weight from "v"
            // is it the already existing parent or current parent i.e., "u"?
            if(mst[v] == false && w < weight[v]){
                weight[v] = w;
                parent[v] = u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    //since parent of first node is -1, we cannot start from 1. Hence we are
    //starting from the 2nd node. (first node will be included as parent of second node)
    for(int i=2; i<=n; i++){
        result.push_back(make_pair(make_pair(parent[i], i), weight[i]));
    }
    
    return result;
}




// Approach 2 : GFG
class Solution{
	public:
	
	vector<int> parent, rank;

    void make_set(int v){
        parent[v] = v;
        rank[v] = 0;
    }
    
    //Function to find set of an element v (using path compression technique).
    int find_set(int v){
        if (v == parent[v]){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    
    //Function that does union of two sets x and y (using union by rank).
    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]){
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]){
                rank[a]++;
            }
        }
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<vector<int>> res;
        for(int i=0; i<V; i++){
            vector<int> temp;
            for(int j=0; j<adj[i].size(); j++)  {
                vector<int> x = adj[i][j];
                temp.push_back(x[1]);
                temp.push_back(min(i,x[0]));
                temp.push_back(max(i,x[0]));
                res.push_back(temp);
                temp.clear();
            }
        }
            
        //sorting according to the weight of the edges.
        sort(res.begin(), res.end());
            
        vector<vector<int>> graph;
        for(int i=0; i<res.size(); i+=2){
            graph.push_back(res[i]);
        }
            
        int cost = 0;
        parent.resize(V);
        rank.resize(V);
        for (int i=0; i<V; i++){
            make_set(i);
        } 
        
        for (vector<int> e : graph){
            //if set of e[1] and e[2] is not equal, we update cost 
            //and perform union of the two sets.
            if (find_set(e[1]) != find_set(e[2])) {
                cost += e[0];
                union_sets(e[1], e[2]);
            }
        }
        return cost;
    }
};