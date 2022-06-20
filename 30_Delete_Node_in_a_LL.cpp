// Link : https://leetcode.com/problems/delete-node-in-a-linked-list/


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
    void deleteNode(ListNode* node) {
        
        ListNode* prev = node;
        while(node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        
        prev->next = NULL;
    }
};

// approach 2:
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* dltNode = node->next;
        node->next = node->next->next;
        dltNode->next = NULL;    
    }
};