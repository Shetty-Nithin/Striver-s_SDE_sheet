// Link : https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// Approach 1: Recursive
void solve(vector<vector<int>> &traversal, BinaryTreeNode *root){
    if(root == NULL){
        return;
    }
    traversal[1].push_back(root->data);
    solve(traversal, root->left);
    traversal[0].push_back(root->data);
    solve(traversal, root->right);
    traversal[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    vector<vector<int>> traversal(3);
    solve(traversal, root);
    
    return traversal;
}


// Approach 2: Iterative
vector<vector<int>> getTreeTraversal(BinaryTreeNode *root){
    vector<vector<int>> traversal(3);
    stack<pair<BinaryTreeNode*, int>> st;
    st.push(make_pair(root, 1));
    
    if(root == NULL) return traversal;
    
    while(!st.empty()){
        pair<BinaryTreeNode*, int> temp = st.top();
        st.pop();
        
        if(temp.second == 1){
            traversal[1].push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            
            if(temp.first->left != NULL){
                st.push(make_pair(temp.first->left, 1));
            }
        }
        else if(temp.second == 2){
            traversal[0].push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            
            if(temp.first->right != NULL){
                st.push(make_pair(temp.first->right, 1));
            }
        }
        else{
            traversal[2].push_back(temp.first->data);
        }
    }
    
    return traversal;   
}