// Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isPossible(bool graph[101][101], int n, int node, int color[], int c){
    for(int i=0; i<n; i++){
        if(i != node && graph[i][node] == 1 && color[i] == c){
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101], int m, int n, int node, int color[]){
    if(node == n){
        return true;
    }
    
    for(int c=1; c<=m; c++){
        if(isPossible(graph, n, node, color, c)){
            color[node] = c;
            if(solve(graph, m, n, node+1, color)){
                return true;
            }else{
                color[node] = 0;
            } 
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[8] = {0}; // n=859_
    if(solve(graph, m, n, 0, color)) return true;
    return false;
}