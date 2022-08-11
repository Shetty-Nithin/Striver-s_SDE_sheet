// Link : https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/

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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> preOrder;
        TreeNode* curr = root;
        
        while(curr){ 
            if(curr->left){
                TreeNode* succecessor = curr->left;
                while(succecessor->right && succecessor->right != curr){
                    succecessor = succecessor->right;
                }
                if(succecessor->right == NULL){
                    preOrder.push_back(curr->val);
                    succecessor->right = curr;
                    curr = curr->left;
                }
                else{
                    succecessor->right = NULL;
                    curr = curr->right;
                }
            }
            else{
                preOrder.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return preOrder;
    }
};