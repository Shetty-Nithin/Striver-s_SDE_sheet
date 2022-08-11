// Link : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> leftView(Node *root)
{
   vector<int> left_view;
   map<int, int> m;
   queue<pair<Node*, int>> q;
   
   if(root == NULL) return left_view;
   
   q.push(make_pair(root, 0));
   while(!q.empty()){
       pair<Node*, int> temp = q.front();
       q.pop();
       
       Node* leftNode = temp.first;
       int level = temp.second;
       
       if(m.find(level) == m.end()){
           m[level] = leftNode->data;
       }
       
       if(leftNode->left){
           q.push(make_pair(leftNode->left, level+1));
       }
       if(leftNode->right){
           q.push(make_pair(leftNode->right, level+1));
       }
    }
   
   for(auto e : m){
       left_view.push_back(e.second);
   }
   
   return left_view;
}