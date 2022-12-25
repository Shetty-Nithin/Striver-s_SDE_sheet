// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int buy = 0;
        int sell = 1;
        
        int tempProfit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[buy] > prices[i]){
                buy = i;
                tempProfit = 0;
            }else{
                tempProfit = prices[sell] - prices[buy];
                profit = max(profit, tempProfit);
            }
            sell++; // sell = i
        }
        
        return profit;
    }
};


// Approach 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int boughtAt = INT_MAX;

        for(int i=0; i<prices.size(); i++){
            boughtAt = min(boughtAt, prices[i]);
            profit = max(profit, prices[i]-boughtAt);
        }
        
        return profit;
    }
};

// Approach 3 : 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        int n = prices.size();

        for(int i=1; i<n; i++){
            int diff = prices[i]-mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};