// Link : https://www.codingninjas.com/codestudio/problems/799897?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1 
// Link : https://leetcode.com/problems/reverse-linked-list/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>

class LinkedListNode{
public:
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(T data){
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {  
        LinkedListNode<int>* prevNode = NULL;
        LinkedListNode<int>* currNode = head;
        LinkedListNode<int>* nextNode = head;
        
        while(nextNode){
            nextNode = currNode->next; // saving the link to the original list
            currNode->next = prevNode; // changin the direction of next

            prevNode = currNode; // updating the prevNod and currNode for next iteration
            currNode = nextNode;
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
        if(head == NULL || head->next == NULL){ // base case: smallest valid test case
            return head;
        }
        
        ListNode* newHead = reverseList(head->next); // cannot use head beacuse, cannot track the previous of head. Thats why sending
                                                     // head->next, so that we can track the previous of head i.e., head
        head->next->next = head;  // changing the direction.
        head->next = NULL; // use full for the last element of the new list (i.e., firs element of the given list)
        
        return newHead;
    }
};