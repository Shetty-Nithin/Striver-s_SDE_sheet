// Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZag;
        queue<TreeNode*> q;
        
        if(root == NULL) return zigZag;
        
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> currLevel(size);
            
            TreeNode* frontNode;
            for(int i=0; i<size; i++){
                frontNode = q.front();
                q.pop();
                
                int index = leftToRight ? i : size-i-1;
                currLevel[index] = frontNode->val;
                
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
    
            zigZag.push_back(currLevel);
            leftToRight = !leftToRight;
        }
    
        return zigZag;
    }
};