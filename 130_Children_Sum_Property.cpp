// Link : https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void incrementChildValues(BinaryTreeNode* root, int diff){
    if(root->right != NULL){
        root->right->data += diff;
        incrementChildValues(root->right, diff);
    }
    else if(root->left != NULL){
        root->left->data += diff;
        incrementChildValues(root->left, diff);
    }
}

void solve(BinaryTreeNode* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    
    solve(root->left);
    solve(root->right);
    
    int childVal = 0;
    if(root->left != NULL) childVal += root->left->data;
    if(root->right != NULL) childVal += root->right->data;
    
    int diff = childVal - root->data;
    if(diff > 0){
        root->data = childVal;
    }
    else{
        incrementChildValues(root, -diff);
    }
}

void changeTree(BinaryTreeNode * root) {
    solve(root);
} 