// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Approach 1 : Recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        if(p->val < root->val && q->val <root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};


// Approach 2 : Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while(true){
            if(p->val < curr->val && q->val < curr->val){
                curr = curr->left;
            }
            else if(p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            }
            else break;
        }
        
        return curr;
    }
};