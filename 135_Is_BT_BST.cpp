// Link : https://leetcode.com/problems/validate-binary-search-tree/

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


// Approach 1 : Recursive
class Solution {
    bool solve(TreeNode* root, long min, long max){
        if(root == NULL){
            return true;
        }
        
        if(root->val <= min || root->val >= max){
            return false;
        }
        
        bool leftAns = solve(root->left, min, root->val);
        bool rightAns = solve(root->right, root->val, max);

        return leftAns && rightAns;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};


// Approach 2 : Iterative
class Solution {
    void inOrder(TreeNode* root, vector<int> &v){
        if(root->left) inOrder(root->left, v);
        v.push_back(root->val);
        if(root->right) inOrder(root->right, v);
    }
public:
    bool isValidBST(TreeNode* root) { 
        if(root == NULL){
            return true;
        }
        
        vector<int> v;
        inOrder(root, v);
        
        for(int i=1; i<v.size(); i++){
            if(v[i] <= v[i-1]){
                return false;
            }
        }
        return true;
    }
};