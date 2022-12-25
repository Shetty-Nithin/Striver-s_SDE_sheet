// Link : https://leetcode.com/problems/linked-list-cycle/


#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// can use the hashing instead of 2 pointer. 
// slow-fast algorithm (hare-tortoise algorithm)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            fast = fast->next;
            
            if(slow == fast){
                return true;
            }
            
            fast = fast->next;
            slow = slow->next;
        }
        
        return false;
    }
};