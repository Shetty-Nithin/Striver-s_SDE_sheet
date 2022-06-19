// Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#
// Link : 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   

        unordered_map<int, int> u_map;
        int maxi = 0;
        int sum = 0;
        
        for(int i=0; i<A.size(); i++){
            
            sum += A[i];
            if(sum == 0){
                maxi = i+1;
            }
            else{
                if(u_map.find(sum) != u_map.end()){
                    maxi = max(maxi, i-u_map[sum]);
                }else{
                    u_map.insert({sum, i});
                }
            }
        }
        
        return maxi;
    }
};