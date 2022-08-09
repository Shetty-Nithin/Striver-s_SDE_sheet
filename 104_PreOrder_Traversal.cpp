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


// Approach 1: Recursion
class Solution {
    void solve(vector<int> &preOrder, TreeNode* root){
        if(root == NULL){
            return;
        }
        
        preOrder.push_back(root->val);
        solve(preOrder, root->left);
        solve(preOrder, root->right);
    }  
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        solve(preOrder, root);
        
        return preOrder;
    }
};


// Approach 2: Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        while(!s.empty() || curr != NULL){
            if(curr){
                preOrder.push_back(curr->val);
                s.push(curr);
                curr = curr->left;
            }
            else{
                curr = s.top();
                s.pop();
                curr = curr->right;
            }
        }
        
        return preOrder;
    }
};


// Approach 3: Morris PreOrder Traversal
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