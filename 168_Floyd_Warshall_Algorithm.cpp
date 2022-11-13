// Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
// Link : https://www.codingninjas.com/codestudio/problems/2041979?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Link : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Dijkstra's algo : TC - O((V + ElogV) * V) for dense graph the TC will become O(V2 + V3logV + C);
Floyd Warshall : TC - O(V3)
*/

// Appraoch 1 : Naive approach using Dijkstra's algorithm
class Solution {
private:
    bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(int i=0; i<n; i++){
            set<pair<int, int>> st;
            st.insert(make_pair(0, i));
            
            while(!st.empty()){
                auto top = *(st.begin());
                st.erase(st.begin());
                
                int nodeDist = top.first;
                int topNode = top.second;
                for(auto neighbour : adjList[topNode]){
                    if(nodeDist + neighbour.second < dist[i][neighbour.first]){
                        auto record = st.find(make_pair(dist[i][neighbour.first], neighbour.first));
                        if(record != st.end()){
                            st.erase(record);
                        }
                        dist[i][neighbour.first] = nodeDist + neighbour.second;
                        st.insert(make_pair(dist[i][neighbour.first], neighbour.first));
                    }
                }
            }
        }

        vector<int> cities(n);
        for(int i=0; i<dist.size(); i++){
            int count = 0;
            for(auto j : dist[i]){
                if( j <= distanceThreshold){
                    count++;
                }
            }
            cities[i] = count;
        }

        int mini = INT_MAX;
        for(int i=0; i<cities.size(); i++){
            if(cities[i] < mini){
                mini = cities[i];
            }
        }

        vector<int> nodesWithLessNgbr;
        for(int i=0; i<cities.size(); i++){
            if(cities[i] == mini){
                nodesWithLessNgbr.push_back(i);
            }
        }

        int size = nodesWithLessNgbr.size();
        return nodesWithLessNgbr[size-1];
    }
};

// Approach 2 : Floyd Warshall Algorithm
class Solution {
private:
    bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); //adjacency matrix
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }
        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];
            int w = edge[2];

            dist[i][j] = w;
            dist[j][i] = w;
        }

        for (int k=0; k<n; ++k) { // intermediate vertex
		    for (int i=0; i<n; ++i) { // source vertex
		        for (int j=0; j<n; ++j) { // destination vertex
		            if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX && (dist[i][k] + dist[k][j]) < INT_MAX){
		                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
		            }
		        }
		    }
		}
  
        vector<int> cities(n);
        int mini = INT_MAX;
        for(int i=0; i<dist.size(); i++){
            int count = 0;
            for(auto j : dist[i]){
                if( j <= distanceThreshold){
                    count++;
                }
            }
            cities[i] = count;
            mini = min(mini, count);
        }

        vector<int> nodesWithLessNgbr;
        for(int i=0; i<cities.size(); i++){
            if(cities[i] == mini){
                nodesWithLessNgbr.push_back(i);
            }
        }

        int size = nodesWithLessNgbr.size();
        return nodesWithLessNgbr[size-1];
    }
};