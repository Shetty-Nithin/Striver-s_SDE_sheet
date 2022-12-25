// Link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool static comparator(pair<int, int> p1, pair<int, int> p2){
    double v1 = (double)(p1.second) / (double)(p1.first);
    double v2 = (double)(p2.second) / (double)(p2.first);
    
    return v1 > v2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    sort(items.begin(), items.end(), comparator);
    
    double maxValue = 0.0;
    for(int i=0; i<n; i++){
        if(w >= items[i].first){
            w -= items[i].first;
            maxValue += items[i].second;
        }else{
            maxValue += (items[i].second/ (double)(items[i].first))*(double)w; // adding the fraction of an item[i], as per the reamining capacity left.
            break;
        }       
    }
    
    return maxValue;
}