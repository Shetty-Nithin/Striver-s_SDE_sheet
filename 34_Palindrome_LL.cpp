// Link : https://leetcode.com/problems/palindrome-linked-list/


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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head;
        
        while(nextNode){
            curr = nextNode;
            nextNode = curr->next;
            
            curr->next = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        
        slow->next = reverseLL(slow->next);
        
        ListNode* first_pointer = head;
        ListNode* second_pointer = slow->next;
        
        while(second_pointer){
            if(first_pointer->val != second_pointer->val){
                return false;
            }
            first_pointer = first_pointer->next;
            second_pointer = second_pointer->next;
        }
        return true;
    }
};



// coding ninja

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) 
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int>* reverseLL(LinkedListNode<int>* head){
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* nextNode = head;

    while(nextNode){
        curr = nextNode;
        nextNode = curr->next;

        curr->next = prev;
        prev = curr;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int>* head) {

    if(head == NULL){
        return true;
    }
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    
    int len = 1;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
        len++;
        if(fast->next){
            fast = fast->next;
            len++;
        }
    }
    
    LinkedListNode<int>* secondList = new LinkedListNode<int> (-1);
    if(len % 2 == 0){
        secondList->next = reverseLL(slow);
    }
    else{
       secondList->next = reverseLL(slow->next); 
    }

    LinkedListNode<int>* first_pointer = head;
    LinkedListNode<int>* second_pointer = secondList->next;

    while(second_pointer){
        if(first_pointer->data != second_pointer->data){
            return false;
        }
        first_pointer = first_pointer->next;
        second_pointer = second_pointer->next;
    }
    return true;
}