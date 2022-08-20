// Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// Approach 1 : Iterative method

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int currQSize = q.size();
            Node* front;
            
            for(int i=0; i<currQSize; i++){
                front = q.front();
                q.pop();
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                
                if(i == currQSize-1){
                    front->next = NULL;   
                }
                else{
                    front->next = q.front();
                }
            }
        }
        return root;
    }
};

// Approach 2 : Recursive method

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        
        if (root->left) {
            root->left->next = root->right;
            if (root->next) {
                root->right->next = root->next->left;
            }
            connect(root->left);
            connect(root->right);
        }
        
        return root;
    }
};