// Link : https://leetcode.com/problems/maximum-subarray/


// Kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = INT_MIN;
        int tempSum = 0;
        for(int i=0; i<nums.size(); i++){
            tempSum += nums[i];
            sum = max(sum, tempSum);
            
            if(tempSum < 0){
                tempSum = 0;
            }
        }
        
        return sum;
    }
};