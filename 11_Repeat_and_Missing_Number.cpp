// Link : https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}


// approach 2:
vector<int> repeatedNumber(const vector<int> &A, vector<int>& ans) {

    sort(A.begin(), A.end());
    
    for(int i=0; i<A.size(); i++){
        if(A[i] != i+1){
            ans[0] = A[i];
            ans[1] = i+1;
            return ans;
        }
    }

    return ans;
}

int main(){

    vector<int> arr{3, 1, 2, 5, 3};

    vector<int> ans(2);
    repeatedNumber(arr, ans);
    
    for(auto i : ans){
        cout << i << " ";
    }
}