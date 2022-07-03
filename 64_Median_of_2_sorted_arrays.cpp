// Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//Brute Force

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> res;
        for(int i=0; i<nums1.size(); i++){
            res.push_back(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++){
            res.push_back(nums2[i]);
        }
        
        sort(res.begin(), res.end());
        
        int n = res.size();
        if(n%2 == 1){
            return res[n/2];
        }else{
            double avg = (res[n/2-1] + res[n/2])/2;
            return avg;
        }
    }
};


// Approach 2 : Using merge for (m+n)/2 + 1;
class Solution {
private:
    void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &nums, int n){
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        
        while(n > 0 && n1 < nums1.size() && n2 < nums2.size()){
            if(nums1[n1] < nums2[n2]){
                nums[n3] = nums1[n1];
                n1++;
            }else{
                nums[n3] = nums2[n2];
                n2++;
            }
            n3++;
            n--;
        }

        while(n > 0 && n1 < nums1.size()){
            nums[n3] = nums1[n1];
            n1++;
        
            n3++;
            n--;
        }

        while(n > 0 && n2 < nums2.size()){
            nums[n3] = nums2[n2];
            n2++;
        
            n3++;
            n--;
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1+n2)/2 +1;
        
        vector<int> nums(n);
        merge(nums1, nums2, nums, n);
        
        if((n1+n2)%2 == 0){
            return (double)((nums[n-2] + nums[n-1])/2.0);
        }else{
            return nums[n-1];
        }
    }
};

// Optimal Approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0;
        int high = nums1.size();
        int medianPos = ((n1+n2)+1)/2;
        
        int mid1;
        int mid2;
        while(low <= high){
            mid1 = (low + high)/2;
            mid2 = medianPos - mid1;
            
            int l1 = (mid1 == 0)? INT_MIN:nums1[mid1-1];
            int l2 = (mid2 == 0)? INT_MIN:nums2[mid2-1];
            int r1 = (mid1 == n1)? INT_MAX:nums1[mid1];
            int r2 = (mid2 == n2)? INT_MAX:nums2[mid2];
            
            if(l1 <= r2 &&  l2 <= r1){
                if((n1+n2)%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }
            else if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }
        
        return 0.0;

    }
}; 