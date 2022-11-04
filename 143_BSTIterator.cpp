// Link : https://leetcode.com/problems/binary-search-tree-iterator/description/


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

class BSTIterator {
private:
    void inOrder(TreeNode* root, vector<int> &inOrderBST){
        if(root == NULL) return;

        inOrder(root->left, inOrderBST);
        inOrderBST.push_back(root->val);
        inOrder(root->right, inOrderBST);
    };

    int pointer;
    int size;
    vector<int> inOrderBST;
public:
    BSTIterator(TreeNode* root) {
        pointer = 0;
        inOrder(root, inOrderBST);
        size = inOrderBST.size();
    }
    
    int next() {
        return inOrderBST[pointer++];
    }
    
    bool hasNext() {
        if(pointer < size) return true;
        return false;
    }
};