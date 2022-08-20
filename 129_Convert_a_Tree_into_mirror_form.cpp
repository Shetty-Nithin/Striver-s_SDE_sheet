// Link : https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* solve(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* temp = solve(root->right);
        root->right = solve(root->left);
        root->left = temp;
        
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};




// Coding ninjas slightly differenc problem
template <typename T>
class TreeNode1 {
    public:
    T data;
    TreeNode1<int> *left;
    TreeNode1<int> *right;

    TreeNode1(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool pathStorer(TreeNode1<int>* root, TreeNode1<int>* leaf, stack<TreeNode1<int>*> &st){
    st.push(root);
    if(root->left == NULL & root->right == NULL){
        if(root->data == leaf->data){
            return true;
        }
        else{
            st.pop();
            return false;
        }
    }
    
    bool leftAns = false, rightAns = false;
    
    if(root->left != NULL){
        leftAns = pathStorer(root->left, leaf, st);
    }
    if(leftAns) return true;
    
    if(root->right != NULL){
        rightAns = pathStorer(root->right, leaf, st);
    }
    if(rightAns) return true;
    
    st.pop();
    return false;
}

TreeNode1<int> * invertBinaryTree(TreeNode1<int> *root, TreeNode1<int> *leaf){
    if(root == NULL) return root;
    
	stack<TreeNode1<int>*> st;
    pathStorer(root, leaf, st);
    
    TreeNode1<int>* newRoot = st.top();
    st.pop();
    TreeNode1<int>* parent = newRoot;
    
    while(!st.empty()){
        TreeNode1<int>* currNode = st.top();
        st.pop();
        
        if(currNode->left == parent){
            currNode->left = NULL;
            parent->left = currNode;
        }
        else{
            currNode->right = currNode->left;
            currNode->left = NULL;
            parent->left = currNode;
        }
        
        parent = parent->left;
    }
    
    return newRoot;
}