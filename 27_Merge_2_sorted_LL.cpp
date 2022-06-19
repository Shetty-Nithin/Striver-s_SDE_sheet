// Link : https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
 
void solve(ListNode* list1, ListNode* list2){
    ListNode* curr_1 = list1;
    ListNode* next_1 = list1->next;
    
    ListNode* curr_2 = list2;
    ListNode* next_2 = list2->next;
    
    while(next_1 && curr_2){
        if(curr_1->val <= curr_2->val && next_1->val >= curr_2->val){
            curr_1->next = curr_2;
            next_2 = curr_2->next;
            curr_2->next = next_1;
            
            curr_1 = curr_2;
            curr_2 = next_2;
        }else{
            curr_1 = next_1;
            next_1 = next_1->next;
        }      
    }
    
    if(next_1 == NULL){
        curr_1->next = curr_2;
        return;
    }
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    
    if(list1->val < list2->val){
        solve(list1, list2);
        return list1;
    }else{
        solve(list2, list1);
        return list2;
    }
}