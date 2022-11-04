// Link : https://www.codingninjas.com/codestudio/problems/920441?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// Approach 1 : O(N) space complextiy
void inOrder(TreeNode<int> *root, vector<int> &in){
    if(root == NULL) return;
    
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	vector<int> in;
    inOrder(root, in);
    
    return in[k-1];
}



// Approach 2 : O(1) space complexity
void solve(TreeNode<int> *root, int k, int &val, int &count){
    if(root == NULL){
        return;
    }
    if(k == count){
        val = root->data;
        count++;
        return;
    }
    
    solve(root->left, k, val, count);
    if(val != -1) return;
    
    count++;
    if(count == k){
        count++;
        val = root->data;
    }
    
    solve(root->right, k, val, count);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	int count = 0;
    int val = -1;
    
    solve(root, k, val, count);
    return val;
}