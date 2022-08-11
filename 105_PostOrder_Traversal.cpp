// Link : https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/

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
    void solve(vector<int> &postOrder, TreeNode* root){
        if(root == NULL){
            return;
        }
        
        solve(postOrder, root->left);
        solve(postOrder, root->right);
        postOrder.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        solve(postOrder, root);
        
        return postOrder;
    }
};

// Approach 2: Iterative using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        stack<TreeNode*> s1, s2;
        
        TreeNode* curr = NULL;
        s1.push(root);
        
        if(root == NULL){
            return postOrder;
        }
        
        while(root != NULL && !s1.empty()){
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            
            if(curr->left){
                s1.push(curr->left);
            }
            if(curr->right){
                s1.push(curr->right);
            }
        }
        while(!s2.empty()){
            postOrder.push_back(s2.top()->val);
            s2.pop();
        }
        
        return postOrder;
    }
};

// Approach 3 : Morris PostOrder Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> postOrder;
        TreeNode* curr = root;
        
        while(curr){
            if(curr->right){
                TreeNode* pred = curr->right;
                while(pred->left && pred->left != curr){
                    pred = pred->left;
                }
                if(pred->left == NULL){
                    postOrder.push_back(curr->val);
                    pred->left = curr;
                    curr = curr->right;
                }
                else{
                    pred->left = NULL;
                    curr = curr->left;
                }
            }
            else{
                postOrder.push_back(curr->val);
                curr = curr->left;
            }
        }
        
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};