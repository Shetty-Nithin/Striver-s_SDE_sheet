// Link : https://leetcode.com/problems/trapping-rain-water/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) { 
        int n = height.size();
        int waterTrapped = 0;

        for(int i=0; i<n; i++){    
            int leftMax = 0;
            int rightMax = 0;
            
            // leftMax
            int j=i;
            while(j >= 0){
                leftMax = max(leftMax, height[j]);
                j--;
            }
            
            // rightMax
            j=i;
            while(j < n){
                rightMax = max(rightMax, height[j]);
                j++;
            }
            
            waterTrapped += min(leftMax, rightMax) - height[i];
        }
        
        return waterTrapped;
    }
};


// approach 2:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        int leftMax[5]; //     int leftMax[n];
        int rightMax[5]; //    int rightMax[n];
        
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i=0; i<n; i++){ 
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return waterTrapped;
    }
};

//approach 3: Optimal solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int waterTrapped = 0;
        int leftMax = 0;
        int rightMax = 0;
        
        int leftPointer = 0;
        int rightPointer = n-1;
        
        while(leftPointer <= rightPointer){
            if(height[leftPointer] <= height[rightPointer]){
                if(height[leftPointer] >= leftMax){ // if yes, we got new higher wall. So we can udpate the wall to trap more water
                    leftMax = height[leftPointer];
                }else{ // since leftMax is > current height, left boundary is available, hence water can be trapped.
                    waterTrapped += leftMax - height[leftPointer];
                }
                leftPointer++;
            }else{
                if(height[rightPointer] >= rightMax){
                    rightMax = height[rightPointer];
                }else{
                    waterTrapped += rightMax - height[rightPointer];
                }
                rightPointer--;
            }
        }
        
        return waterTrapped;
    }
};