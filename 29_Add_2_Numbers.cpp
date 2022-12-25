// Link : https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTail = ansHead;
        
        int sum = 0;
        int carry = 0;
        int num1 = 0;
        int num2 = 0;
        int tempSum = 0;
        while(head1 || head2 || carry){
            if(head1){
                num1 = head1->val;
                head1 = head1->next;
            }else{
                num1 = 0;
            }
            
            if(head2){
                num2 = head2->val;
                head2 = head2->next;
            }else{
                num2 = 0;
            }
            
            tempSum = carry + num1 + num2;
            sum = tempSum % 10;
            carry = tempSum / 10;
            
            ansTail->next = new ListNode(sum);
            ansTail = ansTail->next;
        }
        
        return ansHead->next;
    }
};