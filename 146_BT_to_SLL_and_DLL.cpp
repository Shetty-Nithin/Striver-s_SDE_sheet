// Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Link : https://www.codingninjas.com/codestudio/problems/893106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// SLL : LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        } 
    }
};


// DDL : Coding Ninja
// Approach 1 : getting TLE
template <typename T>
class BinaryTreeNode 
{
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return root;
    }

    if(root->left != NULL){
        BinaryTreeNode<int>* pred = BTtoDLL(root->left);

        // Inorder predecessor.
        while(pred->right != NULL){
            pred = pred->right;
        }
        pred->right = root;
        root->left = pred;
    }
    if(root->right != NULL){
        BinaryTreeNode<int>* succ = BTtoDLL(root->right);

        // Inorder successor.
        while(succ->left != NULL){
            succ = succ->left;
        }
        succ->left = root;
        root->right = succ;
    }

    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

// Approach 2 :
void solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &pre, BinaryTreeNode<int>* &head){
      if(root == NULL){
          return;
      }
     
      solve(root->left, pre, head);
      if(pre == NULL){
          head = root;
      }
      else{
          pre->right = root;
          root->left = head;
      }
      pre = root;
    
      solve(root->right, pre, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* pre = NULL;
    BinaryTreeNode<int>* head = NULL;
    solve(root, pre, head);
    
    return head;
}