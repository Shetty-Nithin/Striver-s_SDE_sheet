// Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// checking if any of the adjacent node is painted with the same color.
bool isPossible(bool graph[101][101], int n, int node, int color[], int c){
    for(int i=0; i<n; i++){
        if(i != node && graph[i][node] == 1 && color[i] == c){ 
            // condition 1: not the node itself
            // condition 2: if the node i is the adjacent node of "node"
            // condition 3: If the adjacent node has the same color as current node
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int m, int n, int node, int color[]){
    if(node == n){
        return true; // all node are colored successfully
    }
    
    for(int c=1; c<=m; c++){
        if(isPossible(graph, n, node, color, c)){ // means : is it possible to paint node "node" with color c?
            color[node] = c;
            if(solve(graph, m, n, node+1, color)){
                return true; // return true, because no need to check with the remaining color(existing the for loop by returning true)
            }else{
                color[node] = 0; // for loop continues with the next color
            } 
        }
    }
    return false; // if the color is not enough to paint all the nodes as per the condition i.e., for loop is exausted
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[8] = {0}; // n=8
    if(solve(graph, m, n, 0, color)) return true;
    return false;
}