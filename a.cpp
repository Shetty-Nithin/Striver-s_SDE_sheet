

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int left = 0;
    int right = INT_MAX;
    int totalSize = A.size() * A[0].size();
    int mid;

    while(right - left > 1){
        mid = left + (right - left) / 2;
        int count = 0;
        for(auto &a: A){ 
            int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
            cout << "mid is : " << mid << endl;
            count += p;
            cout << "count is : " << count << endl;
            cout << "------------------" << endl;
        }
        if(count >= (totalSize/2 +1)){
            right = mid;
        }
        else{
            left = mid;
        }
    }   
    cout << right << endl;
    return right;
}


int main()
{
    vector<vector<int>> A =  {  {'1', '3', '5'},
                                {'2', '6', '9'},
                                {'3', '6', '9'}   };

    findMedian(A);
}