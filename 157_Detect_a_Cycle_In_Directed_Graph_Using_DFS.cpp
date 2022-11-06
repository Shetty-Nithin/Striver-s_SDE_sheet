// Link : https://leetcode.com/problems/course-schedule/description/
// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/
// Link : https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isCyclicDFS(int node, vector<bool> &todo, vector<bool> &done, unordered_map<int, list<int>> &adjList){
    
    done[node] = true;
    todo[node] = true;

    for (auto nbr : adjList[node]) {
        if (!done[nbr]) {
            if(isCyclicDFS(nbr, todo, done, adjList)){
                return true;
            }
        }
        else if(todo[nbr]){
            return true;
        }
    }
    todo[node] = false;
    return false;
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adjList;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adjList[v].push_back(u);
        }
        
        vector<bool> done(numCourses, false);
        vector<bool> todo(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(!done[i]){
                if(isCyclicDFS(i, todo, done, adjList)){
                    return false;
                }
            }
        }
        return true;
    }
};