// Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* solve(int parentVal, vector<int> &preorder, int &index){
        if(index >= preorder.size() || preorder[index] > parentVal){
            return NULL;
        }
        
        TreeNode* newNode = new TreeNode(preorder[index++]);

        newNode->left = solve(newNode->val, preorder, index);
        newNode->right = solve(parentVal, preorder, index);
        
        return newNode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(INT_MAX, preorder, index);
    }
};