// Link : https://leetcode.com/problems/max-consecutive-ones/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int tempCount = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                tempCount++;
            }else{
                maxCount = max(maxCount, tempCount);
                tempCount = 0;
            }
        }
        maxCount = max(maxCount, tempCount); // do not forget this line. I usually forget this line.
        return maxCount;
    }
};