// Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedStr = "";
        if(root == NULL){
            return serializedStr;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL){
                serializedStr.append("#,");
            }else{
                serializedStr.append(to_string(frontNode->val) + ',');
            }

            if(frontNode){
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }

        return serializedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                frontNode->left = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(str));
                frontNode->left = newNode;
                q.push(newNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                frontNode->right = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(str));
                frontNode->right = newNode;
                q.push(newNode);
            }
        }

        return root;
    }
};