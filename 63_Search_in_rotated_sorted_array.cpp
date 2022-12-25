// Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Brute Force
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

// Another not working solution
class Solution {
public:
    int search(vector<int>& nums, int target) {   
        int k = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                k++;
                continue;
            }
            else break;
        }
        
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                if(nums.size() > 1){
                    return mid+k+1;
                }
                else return mid+k;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};


// Optimal Approach
class Solution {
public:
    int search(vector<int>& nums, int target) { 
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] >= target){
                    right = mid-1;
                }else{
                    left = mid+1; // Note 1
                }   
            }else{
                if(nums[mid] <= target && nums[right] >= target){
                    left = mid+1;
                }else{
                    right = mid-1; // Note 2
                }
            }
        }
        
        return -1;
    }
};

/*
case 1:
               /
              /         ---> mid can be present in this. Hence "if(nums[left] <= nums[mid])"
             /  
            /   .
                  /
                 /      ---> else condition

case 2: 
               /
              /
             /
            /           ---> Note 1 and Note 2
           /
          /
*/
