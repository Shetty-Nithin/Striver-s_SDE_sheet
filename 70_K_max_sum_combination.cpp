// Link : https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Link : https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int k){
    vector<int> res;
    sort(A.begin(), A.end(), greater<int>()); // descending order
    sort(B.begin(), B.end(), greater<int>());
    
    priority_queue<int> mH; // max heap
    for(int i=0; i<=k/2+1; i++){ // k/2 becuase : max+max. As we go along an array, value will be decreased. Our intension is to get the max values.
        for(int j=0; j<=k/2+1; j++){
            mH.push(A[i]+B[j]);
        }
    }
    
    for(int i=0; i<k; i++){
        res.push_back(mH.top());
        mH.pop();
    }
    
    return res; 
}


// Optimal Solution : 
#include<algorithm>

vector<int> KMaxCombinations(vector<int>& A,vector<int>& B, int K)
{
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    vector<int> ans;
    int N = A.size();

    priority_queue<pair<int, pair<int, int>>> pq;  // max heap
    set<pair<int, int> > my_set;

    pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));
    my_set.insert(make_pair(0, 0));

    for (int count=0; count<K; count++) {
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if(i+1 < N){
            int sum = A[i+1] + B[j];
            pair<int, int> temp1 = make_pair(i+1, j);

            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }

        if(j+1 < N){
            int sum = A[i] + B[j+1];
            pair<int,int>temp1 = make_pair(i, j+1);

            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
    }
    return ans;
}

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> res = KMaxCombinations(A,B,C);
    return res;
}
