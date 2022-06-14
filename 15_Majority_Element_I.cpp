// Link : https://www.codingninjas.com/codestudio/problems/842495?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/majority-element/submissions/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// int findMajorityElement(int nums[], int n) {
//     map<int, int> m;
//     for(int i=0; i<n; i++){
//         m[nums[i]]++;
//     }
      
//     for(auto i : m){
//         if(i.second > n/2){
//             return i.first;
//         }
//     }
//     return -1;
// }

// Boyer Moore’s Voting Algorithm

int majorityElement(vector<int>& nums) {
    
    int count = 0;
    int element = 0;
    
    for(auto num : nums){
        if(count == 0){
            element = num;
        }
        
        if(num == element){
            count++;
        }else{
            count--;
        }
        cout << count << " ";
    }
    cout << endl;
    
    cout << element << endl;
    return element;
}


int main(){
    vector<int> nums = {1,4,4,3,4,1,2,4,2,2};
 
    majorityElement(nums);
}