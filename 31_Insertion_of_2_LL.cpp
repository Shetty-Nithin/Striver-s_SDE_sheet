// Link : https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/

#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        
        while(h2){
            h1 = headA;
            while(h1){
                if(h1 == h2){
                    return h1;
                }
                h1 = h1->next;
            }
            h2 = h2->next;
        }
        
        return NULL;
    }
};



// Using set
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> s;
        
        while(headA){
            s.insert(headA);
            headA = headA->next;
        }
        
        while(headB){
            if(s.find(headB) != s.end()){
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    }
};



// optimal solution
class Solution {
public:
    int getDiff(ListNode *headA, ListNode *headB){
        int headA_len = 0;
        int headB_len = 0;
        
        while(headA || headB){
            if(headA){
                headA_len++;
                headA = headA->next;
            }
            if(headB){
                headB_len++;
                headB = headB->next;
            }
        }
        
        return headA_len - headB_len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int diff = getDiff(headA, headB);
        
        if(diff < 0){
            while(diff != 0){
                headB = headB->next;
                diff++;
            }
        }else if(diff > 0){
            while(diff != 0){
                headA = headA->next;
                diff--;
            }
        }
        
        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};


// optimal solution
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* hA = headA;
        ListNode* hB = headB;

        while(hA != hB) {
            hA = (hA == NULL) ? headB : hA->next;
            hB = (hB == NULL) ? headA : hB->next;
        }

        return hA;
    }
};