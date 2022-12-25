// Link : https://www.interviewbit.com/problems/matrix-median/
// Link :  https://www.codingninjas.com/codestudio/problems/873378?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<algorithm>
#include<string>
using namespace std;

// Approach 1:
int findMedian(vector<vector<int>> &A) {
    int left = 0;
    int right = INT_MAX;
    int totalSize = A.size() * A[0].size();
    int mid;

    while(right-left > 1){
        mid = left + (right-left) / 2;
        int count = 0;
        for(auto &a: A){  // a is a whole row
            int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
            count += p;
        }
        if(count >= (totalSize/2 +1)){
            right = mid;
        }
        else{
            left = mid;
        }
    }   
    return right;
}


// Approach 2:
int getMedian(vector<vector<int>> &matrix){
    int low = 0;
    int high = INT_MAX; // Note 1
    int totalSize = matrix.size()*matrix[0].size();
    int mid;
    while((high-low) > 1){
        mid = low + (high-low)/2;
        int count = 0;
        for(auto m : matrix){ // m is a whole row    
            int p = upper_bound(m.begin(), m.end(), mid) - m.begin(); // Note 2
            count += p;
        }
        
        if(count > (totalSize/2)){
            high = mid;
        }else{
            low = mid;
        }
    }
    
    return high;
}



/*
Note 1:
    We cannot use high = matrix[row][col]; 
    where :
        row = matrix.size()-1
        col = matrix[0].size()-1
    Becase, rows are not continuation of previous rows.
    If rows are continuation of previous roww like below example, we can use the above line of code.
    ex: 
        1 2 3 
        4 5 6
        7 8 9


/*
Note 2:
    upper_bound : It returns an iterator pointing to the first element in the range [first, last) 
    that is greater ( > ) than mid, or last if no such element is found.
    (means including first and excluding last)

    Return type : An iterator to the upper bound of val in the range.
    If all the element in the range compare less than val, the function returns last.
    Examples :
        Input : 10 20 30 30 40 50
        Output : upper_bound for element 30 is at index 4

        Input : 10 20 30 40 50
        Output : upper_bound for element 45 is at index 4

        Input : 10 20 30 40 50
        Output : upper_bound for element 60 is at index 5
    

    The lower_bound() method in C++ is used to return an iterator pointing to the first element 
    in the range [first, last) which has a value not less than val. This means that the function returns 
    an iterator pointing to the next smallest number just greater than or equal( >= ) to that number.

    Return Value: An iterator to the lower bound of val in the range. If all the elements in the range
    compare less than val, the function returns last. If all the elements in the range are larger than val,
    the function returns a pointer to the first element. 

    Examples: 
        Input: 10 20 30 40 50
        Output: lower_bound for element 30 at index 2

        Input: 10 20 30 40 50
        Output: lower_bound for element 35 at index 3

        Input: 10 20 30 40 50
        Output: lower_bound for element 55 at index 5 (Basically, 55 is not present, so it returns end() iterator)

        Input: 10 20 30 30 30 40 50
        Output: lower_bound for element 30 at index 2
*/