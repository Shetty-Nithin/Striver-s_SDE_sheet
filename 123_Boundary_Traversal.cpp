// Link : https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void leftBoundary(vector<int> &boundary, TreeNode<int>* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    boundary.push_back(root->data);
    
    if(root->left)
        leftBoundary(boundary, root->left);
    else leftBoundary(boundary, root->right);
}

void baseBoundary(vector<int> &boundary, TreeNode<int>* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        boundary.push_back(root->data);
        return;
    }
    baseBoundary(boundary, root->left);
    baseBoundary(boundary, root->right);
}

void rightBoundary(vector<int> &boundary, TreeNode<int>* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    if(root->right)
        rightBoundary(boundary, root->right);
    else rightBoundary(boundary, root->left);
    
    boundary.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> boundary;
    if(root == NULL) return boundary;
    boundary.push_back(root->data);
    
    leftBoundary(boundary, root->left);
    baseBoundary(boundary, root->left);
    baseBoundary(boundary, root->right);
    rightBoundary(boundary, root->right);
    
    return boundary;
}