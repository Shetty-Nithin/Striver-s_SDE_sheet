// Link : https://leetcode.com/problems/symmetric-tree/

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
    bool solve(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode == NULL && rightNode == NULL){
            return true;
        }
        if(leftNode == NULL || rightNode == NULL){
            return false;
        }
        
        if(leftNode->val != rightNode->val){
            return false;
        }
        
        return (solve(leftNode->left, rightNode->right)) && (solve(leftNode->right, rightNode->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return solve(root->left, root->right);
    }
};