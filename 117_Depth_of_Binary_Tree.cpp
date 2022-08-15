// Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/

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


// Approach 1 : Iterative

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        int height = 0;
        if(root == NULL) return height;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* currFront = q.front();
            q.pop();
            
            if(currFront == NULL){
                height++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(currFront->left) 
                    q.push(currFront->left);
                if(currFront->right) 
                    q.push(currFront->right);
            }
        }
        
        return height;
    }
};

// Approach 2 : Recursion
class Solution {
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return max(solve(root->left), solve(root->right)) + 1;
    }
    
public:
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        return solve(root);
    }      
};


// Slightly different problem : Height of the BT using inorder traversal and level order traversal.
// Link : https://www.codingninjas.com/codestudio/problems/841416?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

struct Node{
    int height;
    int leftIndex;
    int rightIndex;
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    queue< Node > q;

    Node newNode;
    newNode.height = 0;
    newNode.leftIndex = 0;
    newNode.rightIndex = N - 1;

    q.push(newNode);
    int maxHeight = 0;
    
    map<int, int> m;
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]] = i;
    }

    for(int i = 0; i < N; i++){
        int curr = levelOrder[i];

        Node now = q.front();
        q.pop();

        int currPos = m[levelOrder[i]];
        
        if(currPos > now.leftIndex){
            Node newNode;
            newNode.height = now.height+1;

            maxHeight = max(maxHeight, newNode.height);

            newNode.leftIndex = now.leftIndex;
            newNode.rightIndex = currPos-1;
            q.push(newNode);
        }

        if(currPos < now.rightIndex){
            Node newNode;
            newNode.height=now.height+1;

            maxHeight = max(maxHeight, newNode.height);

            newNode.leftIndex = currPos+1;
            newNode.rightIndex = now.rightIndex;
            q.push(newNode);
        }
    }
    return maxHeight;
}