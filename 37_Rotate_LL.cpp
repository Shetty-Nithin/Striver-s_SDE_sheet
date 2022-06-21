// Link : https://leetcode.com/problems/rotate-list/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int data;
	struct ListNode * next;
	struct ListNode * bottom;
	
	ListNode(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

class Solution {
public:
    int getLen(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL){
            return head;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        int len = getLen(head);
        if(k >= len){
            k = k%len;
        }
        
        while(k){
            fast = fast->next;
            k--;
        }
        
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        
        return newHead;
    }
};