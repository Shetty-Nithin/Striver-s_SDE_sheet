// Link : https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469
// Link : https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adjList[u].push_back(make_pair(v, w)); // map( u : list{[first, second],[first, second],...} )
        adjList[v].push_back(make_pair(u, w)); // map( v : list{[first, second],[first, second],...} )
    }
    
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

           // dist, node
    set<pair<int, int>> st; // to keep in sorted order.
    st.insert(make_pair(0, source));
    
    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin()); //removing the begining node (like queue in BFS)
        
        int nodeDist = top.first;
        int topNode = top.second;
                 //(v, w)
        for(auto neighbour : adjList[topNode]){
            // updating the smallest distance from cucrent node to its neighbour node.
            if(nodeDist + neighbour.second < dist[neighbour.first]){ // if current dist is less than existing dist

            // ------------ [Optional] --------------
                //checking if the node neighbour is alreday exists the set.
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                
                //deleting the existing entry of the node neighbour from the set.
                //The reason is already existing data's distance will be more than the current dist.
                if(record != st.end()){
                    st.erase(record);
                }
            // ------------ [Optional] --------------

                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}