// Link : https://leetcode.com/problems/top-k-frequent-elements/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> u_map;
        vector<int> frequentElem;
        priority_queue<pair<int, int>> maxHeap;
        
        for(int num : nums){
            u_map[num]++;
        }
        
        for(auto k_v : u_map){
            maxHeap.push({k_v.second, k_v.first});
        }
        for(int i=0; i<k; i++){
            frequentElem.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return frequentElem;
    }
};



// Aprroach 2: with slight change
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> u_map;
        vector<int> frequentElem;
        priority_queue<pair<int, int>> maxHeap;
        
        for(int num : nums){
            u_map[num]++;
        }
        
        for(auto k_v : u_map){
            maxHeap.push({k_v.second, k_v.first});
            
            if(maxHeap.size() > (int)u_map.size()-k){
                frequentElem.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        
        return frequentElem;
    }
};