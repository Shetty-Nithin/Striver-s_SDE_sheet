// Link : https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1
// Link : https://www.codingninjas.com/codestudio/problems/2041977?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/**
 * Bellman Ford Algorithm can apply on directed graph with negative values
 * but not negative cycle.
 * 
 * If the graph is undirected, then we need to convert into directed first,
 * to apply the Bellman Ford algorithm.
 */


/**
 * In Bellman Ford Algorithm we need to apply the below formula for (n-1) times
 * on all the edges
 * (u -> v)
 * Formula : (dist[u] + w) < dist[v]
 * 
 * The reason why (n-1) time is : Shortest distance path can be the one
 * with max number of edges. And the max possible number of edges, a shortest
 * path can have is (n-1).
 * 
 * After applying the above formula for (n-1) times, apply one more time.
 * If now any of the distance is updated, then it means negative cycle is 
 * present and not possible to find the shortest path and return -1 else
 * return the array of shortest path.
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9); // initializing the distance with the max value. And "+1" because we are running the the loop one more time as per the algo.
    dist[src] = 0; // source to source distance is 0. 

    // apply the equation on "m" number of edges for "n-1" times  
    for(int i=1; i<=n; i++){ // n = vertices
        for(int j=0; j<m; j++){ // m = edges = {{x,y,z},{x,y,z},...}
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){ // dist[u] != 1e9 --> if the source is not at infinite
                dist[v] = dist[u] + w;
            }
        }
    }
    
    //check for negative cycle
    bool flag = false;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + w) < dist[v])){
            flag = true;
            // break;
        }
    }
    
    if(flag == false){
        return dist[dest]; // this is the shortest paht between the give source and destination.
    }
    return -1; // cycle is present, hence cannot find the shortest path between the given source and the destination.
    
}


// Approach 2 : GFG
class Solution {
  public:
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, 1e8);
        dist[src] = 0; 
        bool flag = false;
        for(int i=0; i<=n; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if((dist[u] + w) < dist[v]){
                    dist[v] = dist[u] + w;
                    
                    if(i == n){
                        flag = true;
                    }
                }
            }
        }
        
        if(flag == false) return dist;
        return {-1};
    }
};