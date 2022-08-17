// Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/

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
    void inOrderIndex(vector<int> &inorder, map<int, int> &m){
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
    }
    
    TreeNode* constructBinaryTree(vector<int> &preorder, vector<int> &inorder, map<int, int> &m,
                                  int start, int end, int &preIndex){
        if(preIndex >= preorder.size() || start > end){
            return NULL;
        }
            
        int currRootIndex = m[preorder[preIndex++]];

        TreeNode* newNode = new TreeNode(inorder[currRootIndex]);
        newNode->left = constructBinaryTree(preorder, inorder, m, start, currRootIndex-1, preIndex);
        newNode->right = constructBinaryTree(preorder, inorder, m, currRootIndex+1, end, preIndex);
        
        return newNode;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        inOrderIndex(inorder, m);
        
        int preIndex = 0;
        int inSize = inorder.size();
        
        return constructBinaryTree(preorder, inorder, m, 0, inSize-1, preIndex);   
    }
};