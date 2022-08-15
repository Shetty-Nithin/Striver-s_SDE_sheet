// Link : https://leetcode.com/problems/binary-tree-level-order-traversal/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> level_order;
        queue<TreeNode*> q;
        
        if(root == NULL) return level_order;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            vector<int> curr_level;
            
            while(temp){
                curr_level.push_back(temp->val); 
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
                temp = q.front();
                q.pop();
            }
            level_order.push_back(curr_level);
            
            if(!q.empty()) q.push(NULL);
        }
        
        return level_order;
    }
};