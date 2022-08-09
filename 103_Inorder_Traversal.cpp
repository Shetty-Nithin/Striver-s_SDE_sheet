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
 

// Approach 1 : Using Recursion
class Solution {
    void solve(vector<int> &inOrder, TreeNode* root){
        if(root == NULL){
            return;
        }
        
        solve(inOrder, root->left);
        inOrder.push_back(root->val);
        solve(inOrder, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        
        solve(inOrder, root);
        return inOrder;  
    }
};


// Approach 2 : Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inOrder;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        while(!s.empty() || curr != NULL){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                curr = s.top();
                s.pop();
                inOrder.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return inOrder;
    }
};


// Approach 3 : Morris Inorder Traversal (without using stack)
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
