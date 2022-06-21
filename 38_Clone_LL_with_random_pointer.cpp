// Link : https://leetcode.com/problems/copy-list-with-random-pointer/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertNode(Node* &cloneHead, Node* &cloneTail, int val){
        Node* newNode = new Node(val);
        if(cloneHead == NULL){
            cloneHead = newNode;
            cloneTail = newNode;
        }else{
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
    }
    
    Node* copyRandomList(Node* head) {
        
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        while(temp != NULL){
            insertNode(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        
        unordered_map<Node*, Node*> m;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            m[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        while(cloneNode != NULL){
            cloneNode->random = m[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};