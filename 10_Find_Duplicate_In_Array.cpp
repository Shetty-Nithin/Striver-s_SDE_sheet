// Link : https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Pre-requisite for this algorithm
// * Duplicate number must be present
// * N items contains number from 1 to N-1
int findDuplicate(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}