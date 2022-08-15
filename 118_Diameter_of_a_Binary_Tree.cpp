// Link : https://leetcode.com/problems/diameter-of-binary-tree/submissions/

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
    pair<int, int> solve(TreeNode* root){
        if(root == NULL){
            return make_pair(0, 0);
            //first = diameter
            //second = current height
        }
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        int potentialDiameter_1 = leftAns.first;
        int potentialDiameter_2 = rightAns.first;
        int potentialDiameter_3 = leftAns.second + rightAns.second + 1;
        
        pair<int, int> ans;
        ans.first = max(potentialDiameter_1, max(potentialDiameter_2, potentialDiameter_3));
        ans.second = max(leftAns.second, rightAns.second) + 1;
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first - 1; // since considering the edges not nodes
    }
};