// Link : https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 1 : Few test cases are not passing
template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> * root, int X)
{
    int floor = -1;
    
    while(root){
        if(X == root->val) return root->val;
        else if(X > root->val){
            floor = root->val;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    
    return floor;
}