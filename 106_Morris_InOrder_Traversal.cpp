// Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> inOrder;
        
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* predecessor = curr->left;
                while(predecessor->right && predecessor->right != curr){
                    predecessor = predecessor->right;
                }
                if(predecessor->right == NULL){
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else{
                    inOrder.push_back(curr->val);
                    predecessor->right = NULL; // reason?
                    curr = curr->right;
                }
            }
            else{
                inOrder.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return inOrder;
    }
};