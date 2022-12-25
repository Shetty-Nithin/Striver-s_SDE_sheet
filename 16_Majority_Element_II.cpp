// Link : https://leetcode.com/problems/majority-element-ii/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // only num1 and num2 are taken because only 2 n/3 can present in the n size array.
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        
        for(auto num : nums){
            if(num == num1){
                count1++;   
            }
            else if(num == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = num;
                count1++;   
            }
            else if(count2 == 0){
                num2 = num;
                count2++;   
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(auto num : nums){
            if(num == num1)
                count1++;
            if(num == num2)
                count2++;
        }
        
        vector<int> ans;
        if(count1 > n/3)
            ans.push_back(num1);
        if(num1 != num2 && count2 > n/3)
            ans.push_back(num2);
        
        return ans;
        
    }
};