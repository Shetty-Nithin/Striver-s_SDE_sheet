// Link : https://www.interviewbit.com/problems/path-to-given-node/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool findPath(vector<int> &path, TreeNode* curr, TreeNode* src, int dest)
{
    if(curr == NULL) return false;
    path.push_back(curr->val);
    if(curr->val == dest) return true;
    
    
    if(findPath(path, curr->left, src, dest) || findPath(path, curr->right, src, dest)){
        return true;
    }
    
    path.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int> path;
    TreeNode* curr = A;
    
    findPath(path, curr, A, B);
    return path;
}