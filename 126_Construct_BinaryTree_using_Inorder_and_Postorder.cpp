// Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

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
    void findIndex(vector<int> &inorder, map<int, int> &m){
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i; 
        }
    }
    TreeNode* constructBinaryTree(vector<int> &inorder, map<int, int> &inorder_map, int in_start, int in_end,
                                  vector<int> &postorder, int post_start, int post_end){
        
        if(in_start > in_end || post_start > post_end){
            return NULL;
        }
        
        TreeNode* newNode = new TreeNode(postorder[post_end]);
        
        int in_Root = inorder_map[postorder[post_end]];
            
        newNode->left = constructBinaryTree(inorder, inorder_map, in_start, in_Root-1, postorder, post_start, post_start+in_Root-in_start-1);
        newNode->right = constructBinaryTree(inorder, inorder_map, in_Root+1, in_end, postorder, post_start+in_Root-in_start, post_end-1);
        
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inorder_map;
        findIndex(inorder, inorder_map);
        
        int in_start = 0, in_end = inorder.size()-1;
        int post_start = 0, post_end = postorder.size()-1;
        
        return constructBinaryTree(inorder, inorder_map, in_start, in_end, 
                                   postorder, post_start, post_end);
    }
};
