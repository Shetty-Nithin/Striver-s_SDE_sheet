// Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head;
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        while(nextNode){
            curr = nextNode;
            nextNode = nextNode->next;
            
            curr->next = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = reverseLL(head); 
        ListNode* rmv = NULL;
        
        if(n == 1){
            rmv = newHead;
            newHead = newHead->next; // assigning NULL to newHead
            rmv->next = NULL; // removeing the node by assiging NULL
        }else{
            ListNode* curr = newHead;
            ListNode* prev = NULL;
            while(n-1){
                prev = curr;
                curr = curr->next;
                n--;
            } 
            rmv = curr;
            prev->next = curr->next;   
            rmv->next = NULL;
        }
        
        newHead = reverseLL(newHead);
        return newHead;
    }
};

// optimal approach 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // by maintaining the "n" nodes of difference between slow and fast pointers.
        // As soon as fast reaches the end slow will be at nth position from the end (slow = fast-n)
        ListNode* start = new ListNode();
        start->next = head; 
        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i=1; i<=n; i++){
             fast = fast->next;
        }
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
         
        slow->next = slow->next->next;
        
        return start->next;
    }
};