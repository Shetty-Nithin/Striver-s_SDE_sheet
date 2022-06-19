// Link : https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* tortoise = head;
        ListNode* hare = head->next;  
        
        while(hare != NULL){
            hare = hare->next;
            if(hare != NULL){
                hare = hare->next;
            }
            
            tortoise = tortoise->next;
        }
        
        return tortoise;
    }
};