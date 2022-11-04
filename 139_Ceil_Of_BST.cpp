// Link  :https://www.codingninjas.com/codestudio/problems/920464?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    
    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode *node, int x){
    int ceil = -1;
    
    while(node){
        if(x == node->data) return node->data;
        else if(x < node->data){
            ceil = node->data;
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    
    return ceil;
}