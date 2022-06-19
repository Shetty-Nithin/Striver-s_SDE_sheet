// Link : https://www.codingninjas.com/codestudio/problems/799897?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 
// Link : https://leetcode.com/problems/reverse-linked-list/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{  
        LinkedListNode<int>* prevNode = NULL;
        LinkedListNode<int>* currNode = head;
        LinkedListNode<int>* nextNode = head;
        
        while(nextNode){
            currNode = nextNode;
            nextNode = nextNode->next;
            
            currNode->next = prevNode;
            prevNode = currNode;
        }
        
        return prevNode;
}

// approach 2: Recurrsion

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};