// Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    void inOrder(TreeNode* root, vector<int> &in){
        if(root == NULL) return;

        inOrder(root->left, in);
        in.push_back(root->val);
        inOrder(root->right, in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inOrder(root, in);

        int left = 0;
        int right = in.size()-1;
        int sum = 0;
        while(left < right){
            sum = in[left]+in[right];

            if(sum == k) return true;
            else if(sum > k) right--;
            else left++;
        }

        return false;
    }
};