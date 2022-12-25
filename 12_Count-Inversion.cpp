// Link : https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Inversion Count: 
//                  For an array indicates – how far (or close) the array is from being sorted. 
// If the array is already sorted, then the inversion count is 0, but if the array is sorted in
// reverse order, the inversion count is the maximum. 

// approach 1 : Brute Force
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long getInversions(long long *arr, int n){
    
    long long count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}

// approach 2 : Optimized
#include <bits/stdc++.h> 

long long merge(long long* arr, long long* temp, int left, int mid, int right){
    int i, j, k;
    long long invConv = 0;
    i = left;
    j = mid;
    k = left;

    while((i<=mid-1) && (j<=right)){
        if(arr[i] <= arr[j]){ // if the element is present in the 1st half is < mid element, then keep the 1st half element.
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++]; // else keep the 2nd half element
            invConv = invConv + (mid-1);
        }
    }
    while(i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
    
    return invConv;
}

long long _mergeSort(long long *arr, long long* temp, int left, int right){
    int mid = 0;
    long long invConv = 0;

    // if(right < left) return 0; optional base case
    
    if(right > left){
        mid = (left + right)/2; 
        invConv += _mergeSort(arr, temp, left, mid);
        invConv += _mergeSort(arr, temp, mid+1, right);
        invConv += merge(arr, temp, left, mid+1, right);
    }
    
    return invConv;
}

long long getInversions(long long *arr, int n){
    long long *temp = new long long[n];
    return _mergeSort(arr, temp, 0, n-1);
}

// Approach 3:
#include <vector>
#include <algorithm>

void fenwickUpdate(int index, int siz, vector<long long> &fenwick){
    while (index <= siz){
        // Update the current element in the fenwick vector.
        fenwick[index] += 1;
        // Increase the index to the child index in the fenwick tree.
        index = index + (index & (-index));
    }
}
long long fenwickSum(int index, vector<long long> &fenwick){
    long long sum = 0;
    while (index > 0){
        // Add the value of current node in sum.
        sum += fenwick[index];
        // Move to the parent node of the current node.
        index = index - (index & (-index));
    }
    return sum;
}

long long getInversions(long long *arr, int n) {
    vector<vector<int>> mapping(n, vector<int>(2)); // to store the original index
    vector<long long> fenwick(n + 1, 0), mask(n);

    for (int i = 0; i < n; i++) {
        mapping[i][0] = arr[i];
        mapping[i][1] = i;
    }

    sort(mapping.begin(), mapping.end());
    for (int i = 0; i < n; i++) {
        mask[mapping[i][1]] = i + 1;
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        // Calculate the number of elements greater than the current element.
        answer += fenwickSum(mask[i] - 1, fenwick);
        // Update the element that has been visited.
        fenwickUpdate(mask[i], n, fenwick);
    }
    return answer;
}