// Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/

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
private:
    int solve(TreeNode* root, int &maxSum){
        if(root == NULL) return 0;
        
		int leftAns = max(0, solve(root->left, maxSum));
        int rightAns = max(0, solve(root->right, maxSum));
        
		maxSum = max(maxSum, root->val + leftAns + rightAns);
		
        return root->val + max(leftAns, rightAns);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        if(root == NULL) return 0;
        
		solve(root, maxSum);
        return maxSum;
    }
};