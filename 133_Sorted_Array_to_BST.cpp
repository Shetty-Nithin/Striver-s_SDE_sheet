// Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* solve(vector<int> &nums, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = start + (end - start)/2;
        
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = solve(nums, start, mid-1);
        newNode->right = solve(nums, mid+1, end);
        
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};