// Link : https://www.codingninjas.com/codestudio/problems/893103?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode2 {
    int val;
    TreeNode2 *left;
    TreeNode2 *right;
    TreeNode2() : val(0), left(nullptr), right(nullptr) {}
    TreeNode2(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode2(int x, TreeNode2 *left, TreeNode2 *right) : val(x), left(left), right(right) {}
};

int ans;
class info {
public:
    bool isBST = true;
    int maxSum = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX; 
};
class Solution { 
private:
    info* solve(TreeNode2* root){
        if(root == NULL){
            return new info();
        }

        info* leftAns = solve(root->left);
        info* rightAns = solve(root->right);

        info* currAns = new info();
        currAns->isBST = leftAns->isBST && rightAns->isBST && (root->val > leftAns->maxi) && (root->val < rightAns->mini);
        if(currAns->isBST){
            currAns->maxSum = leftAns->maxSum + root->val + rightAns->maxSum;
        }else{
            currAns->maxSum = max(leftAns->maxSum, rightAns->maxSum);
        }
        currAns->maxi = max(rightAns->maxi, root->val);
        currAns->mini = min(leftAns->mini, root->val);

        ans = max(ans, currAns->maxSum);
        return currAns;
    }
public:
    int maxSumBST(TreeNode2* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};

// Coding Ninja : Slightly different problme
// template <typename T>
// class TreeNode {
//     public :
//     T data;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T data) {
//         this -> data = data;
//         left = NULL;
//         right = NULL;
//     }

//     ~TreeNode() {
//         if(left)
//             delete left;
//         if(right)
//             delete right;
//     }
// };

// class info {
// public:
//     bool isBST = true;
//     int maxSize = 0;
//     int maxi = INT_MIN;
//     int mini = INT_MAX;   
// };

// info* solve(TreeNode<int>* root){
//     if(root == NULL){
//         info* newInfo = new info();
//         return newInfo;
//     }

//     info* leftAns = solve(root->left);
//     info* rightAns = solve(root->right);

//     info* currAns = new info();
//     currAns->isBST = leftAns->isBST && rightAns->isBST && (root->data > leftAns->maxi) && (root->data < rightAns->mini);
//     if(currAns->isBST){
//         currAns->maxSize = leftAns->maxSize + 1 + rightAns->maxSize;
//     }else{
//         currAns->maxSize = max(leftAns->maxSize, rightAns->maxSize);
//     }
//     currAns->maxi = max(rightAns->maxi, root->data);
//     currAns->mini = min(leftAns->mini, root->data);

//     return currAns;
// }
// int largestBST(TreeNode<int>* root) 
// {
//     info* ans = solve(root);
//     return ans->maxSize;
// }