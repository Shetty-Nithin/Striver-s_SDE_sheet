// Link : https://leetcode.com/problems/linked-list-cycle-ii/


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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            
            if(fast && fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};



// approach 2: Brute Force using Hash table

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> st;
        while(head != NULL) {
            if(st.find(head) != st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        return NULL;
    }
};