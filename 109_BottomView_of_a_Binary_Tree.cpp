// Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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

class Solution {
  public:
    vector <int> bottomView(Node *root){
        vector<int> bottomView;
        map<int, int> map_bottomView;
        queue<pair<Node*, int>> q;
        
        if(root == NULL) return bottomView;
        
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int hori_level = temp.second;
            
            map_bottomView[hori_level] = node->data;
            
            if(node->left) q.push(make_pair(node->left, hori_level-1));
            if(node->right) q.push(make_pair(node->right, hori_level+1));
        }
        
        for(auto m : map_bottomView){
            bottomView.push_back(m.second);
        }
        return bottomView;
    }
};