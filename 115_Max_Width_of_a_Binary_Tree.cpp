// Link : https://leetcode.com/problems/maximum-width-of-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Including NULL

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
    int widthOfBinaryTree(TreeNode* root)
    {
        int maxWidth = 0;
        queue<pair<TreeNode*, int>> q;
        
        if(root == NULL) return maxWidth;
        q.push({root, 1});
        
        while(!q.empty())
        {
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            maxWidth = max(maxWidth,  end-start + 1); // finding the width in each level
            
            while(size--){
                int index = q.front().second - start;
                TreeNode* currNode = q.front().first;
                q.pop();
                
                
                if(currNode->left){
                    q.push({currNode->left, (long long)2*index + 1});
                }
                if(currNode->right){
                    q.push ({currNode->right, (long long)2*index + 2}); 
                }
            }
            
        }
        
        return maxWidth;
    }
};


// Slightly different problem : Excluding NULL

template <typename T>
class TreeNode2 {
    public:
    T val;
    TreeNode2<T> *left;
    TreeNode2<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};


int getMaxWidth(TreeNode2<int>*root)
{
int maxWidth = 0;
    queue<TreeNode2<int>*> q;

    if(root == NULL) return maxWidth;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        maxWidth = max(maxWidth,  size);

        while(size--){
            TreeNode2<int>* currNode = q.front();
            q.pop();

            if(currNode->left)
                q.push(currNode->left);
            if(currNode->right)
                q.push (currNode->right); 
        }

    }

    return maxWidth;
}