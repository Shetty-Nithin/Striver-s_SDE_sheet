// Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/


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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, map<int, multiset<int>>> map_verticalOrder;
        vector<vector<int>> verticalOrder;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if(root == NULL){
            return verticalOrder;
        }
        
        q.push(make_pair(root, make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            
            TreeNode* frontNode = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
            map_verticalOrder[col][row].insert(frontNode->val);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(row+1, col-1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(row+1, col+1)));
            }
        }
        
        for(auto m1 : map_verticalOrder){
            vector<int> temp;
            for(auto v : m1.second){
                temp.insert(temp.end(), v.second.begin(), v.second.end());
            }
            verticalOrder.push_back(temp);
        }
        
        return verticalOrder;
    }
};