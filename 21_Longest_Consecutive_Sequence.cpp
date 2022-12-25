// Link : https://leetcode.com/problems/longest-consecutive-sequence/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        
        sort(nums.begin(), nums.end());
        int len = 1;
        int tempLen = 1;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] == nums[i]){
                continue;
            }
            if(nums[i+1]-1 != nums[i]){
                len = max(len, tempLen);
                tempLen = 1;
            }
            else{
                tempLen++;
            }
        }
        
        len = max(len, tempLen);
        
        return len;
    }
};

// approach 2:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num : nums){
            hashSet.insert(num);
        }
        
        int len = 0;
        for(int num : nums){
            if(!hashSet.count(num-1)){
                int currNum = num;
                int currLen = 1;
                
                while(hashSet.count(currNum+1)){
                    currNum += 1;
                    currLen += 1;
                }
                
                len = max(len, currLen);
            }
        }
        
        return len;
    }
};