

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

    long long colosseum(int N,vector<int> A) {
        priority_queue<int, vector<int>, greater<int>> min_Heap_set1;
        priority_queue<int> max_Heap_set1;
        priority_queue<int, vector<int>, greater<int>> min_Heap_set2;
        priority_queue<int> max_Heap_set2;
        priority_queue<int, vector<int>, greater<int>> min_Heap_set3;
        priority_queue<int> max_Heap_set3;
        priority_queue<int, vector<int>, greater<int>> min_Heap_set4;
        priority_queue<int> max_Heap_set4;
        
        for(int i=0; i<N/2; i++){
            min_Heap_set1.push(A[i]);
            max_Heap_set2.push(A[i]);
        }
        for(int i=N/2; i<N; i++){
            max_Heap_set1.push(A[i]);
            min_Heap_set2.push(A[i]);
        }
        for(int i=0; i<N/3; i++){
            min_Heap_set3.push(A[i]);
            max_Heap_set4.push(A[i]);
        }
        for(int i=2*N/3; i<N; i++){
            max_Heap_set3.push(A[i]);
            min_Heap_set4.push(A[i]);
        }
        
        
        for(int i=0; i<N/6; i++){
            min_Heap_set1.pop();
            max_Heap_set2.pop();
            
            max_Heap_set1.pop();
            min_Heap_set2.pop();
        }
        
        long long sum_set1_team1 = 0, sum_set1_team2 = 0;
        long long sum_set2_team1 = 0, sum_set2_team2 = 0;
        long long sum_set3_team1 = 0, sum_set3_team2 = 0;
        long long sum_set4_team1 = 0, sum_set4_team2 = 0;
        
        while(min_Heap_set1.size()){
            sum_set1_team1 += min_Heap_set1.top();
            sum_set1_team2 += max_Heap_set1.top();
            min_Heap_set1.pop();
            max_Heap_set1.pop();
            
            sum_set2_team1 += max_Heap_set2.top();
            sum_set2_team2 += min_Heap_set2.top();
            min_Heap_set2.pop();
            max_Heap_set2.pop();
            
            sum_set3_team1 += min_Heap_set3.top();
            sum_set3_team2 += max_Heap_set3.top();
            min_Heap_set3.pop();
            max_Heap_set3.pop();
            
            sum_set4_team1 += max_Heap_set4.top();
            sum_set4_team2 += min_Heap_set4.top();
            min_Heap_set4.pop();
            max_Heap_set4.pop();
        }
        
        
        long long ans1 = abs(sum_set1_team1 - sum_set1_team2);
        long long ans2 = abs(sum_set2_team1 - sum_set2_team2);
        long long ans3 = abs(sum_set3_team1 - sum_set3_team2);
        long long ans4 = abs(sum_set4_team1 - sum_set4_team2);

        cout <<  max(ans1, max(ans2, max(ans3, ans4))) << endl;
    }


int main()
{
    vector<int> arr =  {1, 1, 5, 3, 7, 7};

    colosseum(2, arr);
}