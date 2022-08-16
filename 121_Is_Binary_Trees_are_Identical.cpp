// Link : https://leetcode.com/problems/same-tree/

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
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if((p == NULL && q != NULL) || (q == NULL && p != NULL) || p->val != q->val){
            return false;
        }
        
        bool leftAns = isIdentical(p->left, q->left);
        bool rightAns = isIdentical(p->right, q->right);
        
        return (leftAns && rightAns);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isIdentical(p, q);
    }
};