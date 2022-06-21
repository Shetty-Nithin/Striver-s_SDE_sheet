// Link : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* mergeSort(Node* root, Node* nextRoot){
    Node* temp = new Node(-1);
    Node* res = temp;
    
    while(root != NULL && nextRoot != NULL){
        if(root->data < nextRoot->data){
            temp->bottom = root;
            root = root->bottom;
            temp = temp->bottom;
        }else{
            temp->bottom = nextRoot;
            nextRoot = nextRoot->bottom;
            temp = temp->bottom;
        }
    }
    
    if(root != NULL){
        temp->bottom = root;
    }
    if(nextRoot != NULL){
        temp->bottom = nextRoot;
    }
    
    return res->bottom;
}

Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    root->next = flatten(root->next);
    return mergeSort(root, root->next);
}