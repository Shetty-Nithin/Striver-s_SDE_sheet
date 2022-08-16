// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        TreeNode* leftAns = solve(root->left, p, q);
        TreeNode* rightAns = solve(root->right, p, q);
        
        if(leftAns && rightAns) return root;
        else if(leftAns && rightAns == NULL) return leftAns;
        else if(rightAns && leftAns == NULL) return rightAns;
        else return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return  solve(root, p, q);  
    }
};