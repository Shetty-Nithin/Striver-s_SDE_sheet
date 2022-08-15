// Link : https://leetcode.com/problems/balanced-binary-tree/

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
    pair<bool, int> solve(TreeNode* root){
        if(root == NULL){
            return make_pair(true, 0);
        }
        
        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);
        
        bool first_part = leftAns.first && rightAns.first;
        bool second_part = (abs(leftAns.second - rightAns.second)) <= 1;
        
        pair<bool, int> ans;
        ans.first = first_part && second_part;
        ans.second = max(leftAns.second, rightAns.second) + 1;
            
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};