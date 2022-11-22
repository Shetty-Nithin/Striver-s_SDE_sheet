// Link : https://leetcode.com/problems/maximum-product-subarray/description/


#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 1 : Brute Force
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int temp = 1;
            for(int j=i; j<nums.size(); j++){
                temp *= nums[j];
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};

// Approach 2 : Kadane's Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int tempProd = 1;
        int store = 1;

        for(int i=0; i<nums.size(); i++){
            tempProd *= nums[i];
            maxProd = max(maxProd, tempProd);

            if(tempProd == 0){ // if 0 appears in between
                tempProd = 1;
                store = 1;
            }
            if(tempProd < 0){ // saving the -ve ans hoping that another -ve num will appear and makes it +ve.
                if(store != 1){ // this ensures that there is no 0 between previous -ve and curr -ve number.
                    maxProd = max(maxProd, store*tempProd);
                }else{
                    store = tempProd;
                    tempProd = 1;
                }
            }
        }
        return maxProd;
    }
};

// Approach 3: Finding from both the side
class Solution {
private:
    int maxProductSubArray(vector<int>& nums) {
        int maxLeft = nums[0];
        int maxRight = nums[0];
        
        int prod = 1;
        bool zeroPresent =  false;
        for(auto i:nums) {
            prod *= i;
            if(i == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxLeft = max(maxLeft,prod);
        }
        
        prod = 1;
        for(int j=nums.size()-1;j>=0;j--) {
            prod *= nums[j];
            if(nums[j] == 0) {
                zeroPresent = true;
                prod = 1;
                continue;
            }
            maxRight = max(maxRight,prod);
        }
        
        if(zeroPresent){
            return max(0, max(maxLeft, maxRight));
        }
        else return max(maxLeft,maxRight);
    }
public:
    int maxProduct(vector<int>& nums) {
        return maxProductSubArray(nums);
    }
};


// Approach 4 : Recurssion
class Solution {
private: 
    long maxProductUtil(vector<int>& nums, int i, bool mustPick) {
        long mini, maxi;
        if (i >= nums.size()){
            if(mustPick) return 1;
            else return INT_MIN;
        }  
        else if (mustPick){
            mini = minProductUtil(nums, i+1);
            maxi = maxProductUtil(nums, i+1, true);

            if(nums[i] >= 0){
                return max(1l, nums[i]*maxi);
            }else{
                return max(1l, nums[i]*mini);
            }         
        }
        else{
            mini = minProductUtil(nums, i+1);
            maxi = maxProductUtil(nums, i+1, true);
            if(nums[i] >= 0){
                return max(maxProductUtil(nums, i+1, false), nums[i]*maxi);
            }
            else{
                return max(maxProductUtil(nums, i+1, false), nums[i]*mini);
            } 
        }
    }

    long minProductUtil(vector<int>& nums, int i) {
        if (i >= nums.size()){
            return 1;
        }
        else if(nums[i] >= 0){
            return nums[i] * minProductUtil(nums, i+1);
        }
        else{
            return nums[i] * maxProductUtil(nums, i+1, true);
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        return maxProductUtil(nums, 0, false);
    }
};


// Approach 5 : Kadane's Algorithm / Bottom-Up with space otimization
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int res = nums[0];

        for(int i=1; i<nums.size(); i++){
            int tempCurrMax = currMax;
            currMax = max(nums[i], max(nums[i]*currMax, nums[i]*currMin));
            currMin = min(nums[i], min(nums[i]*tempCurrMax, nums[i]*currMin));

            res = max(res, currMax);
        }
        return res;
    }
};