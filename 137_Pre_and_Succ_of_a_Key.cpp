// Link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 2 : Recursive

struct Node
{
	int key;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root == NULL){
        return;
    }
    
    if(root->key == key){
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }
    if(root->key > key){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    if(root->key < key){
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}


// Approach 2 : Iterative

template <typename T>

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};


void inOrder(BinaryTreeNode<int>* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    
    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   
    vector<int> v;
    inOrder(root, v);
    
    int pre = -1, suc = -1;
    
    for(int i=0; i<v.size(); i++){
        if(v[i] == key){
            if(i-1 >= 0){
                pre = v[i-1];
            }
            if(i+1 < v.size()){
                suc = v[i+1];
            }
            break;
        }
    }
    
    return {pre, suc};
}