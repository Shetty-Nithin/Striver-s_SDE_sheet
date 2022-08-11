// Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> topView;
        map<int, int> map_topView;
        queue<pair<Node*, int>> q;
        
        if(root == NULL) return topView;
        
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int hori_level = temp.second;
            
            if(map_topView.find(hori_level) == map_topView.end()){
                map_topView[hori_level] = temp.first->data;
            }
            
            if(node->left) q.push(make_pair(node->left, hori_level-1));
            if(node->right) q.push(make_pair(node->right, hori_level+1));
        }
        
        for(auto m : map_topView){
            topView.push_back(m.second);
        }
        return topView;
    }

};