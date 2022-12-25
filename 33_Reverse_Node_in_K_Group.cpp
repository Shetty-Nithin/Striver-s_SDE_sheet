// Link : https://leetcode.com/problems/reverse-nodes-in-k-group/

#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLen(ListNode* head){
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        
        return count;
    }

    ListNode* reverseK(ListNode* head, int k, int len) { 
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head;
        int count = 0;
        
        while(count != k){ // 0, 1, 2, 3 = 4 nodes
            if(curr == NULL){
                return head;
            }
            
            nextNode = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextNode;
            count++;
        }
        len = len-k;
        
        if(len >= k){
            head->next = reverseK(curr, k, len);
        }
        else{ // if reamining are < k, then keep them as it is.
            head->next = curr;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLen(head);
        return reverseK(head, k, len);
    }
};



// coding ninja
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node* reverseK(Node *head, int index, int n, int b[]) {

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = head;
    int count = 0;

    while(curr != NULL && count != b[index]){
        nextNode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;
        count++;
    }
    index++;
    
    if(index < n && curr != NULL){
        head->next = reverseK(curr, index, n, b);
    }
    
    return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    int index = 0;
    return reverseK(head, index, n, b);
}