// Link : https://www.interviewbit.com/problems/allocate-books/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

/*
Note 1: isPossible function checks whether the max of "mid" number of pages can be allocated to each
        student and allocate all the books?
        -> if the book has pages more than "mid" then returns false
        -> if, after allocating max of "mid" number of pages to the B number of student, books are still not
           allocated then also return false.
        -> All the books are allocated and all the B number of students got the books, then return true.

        If the current "mid" number of pages are not possible to distribute the books, then pages less than "mid"
        is also not possible, hence change the search space to [mid+1 to end].

        If the current "mid" number of pages is possible to distribute the books, then reduce the number of pages and
        check again, i.e., change the search space to [start, mid-1]. This is because we need 
        "maximum number of pages allocated to a student is MINIMUM."

Note 2: if the total number of pages allocated a student exceeds "mid", then increase the student size and go 
        for another student.

Note 3: Return false either when all the students are allocated with the books and still some pages are pending
                         or when ith book has pages more than current "mid" number of pages.
*/
bool isPossible(vector<int> &A, int B, int pages){ // Note 1
    int BCount = 1;
    int pageSum = 0;
    
    for(int i=0; i<A.size(); i++){
        if((pageSum + A[i]) <= pages){ // Assigning the books to the student upto the "mid" number of pages
            pageSum += A[i];
        }else{
            BCount++; // Note 2
            if(BCount > B || A[i] > pages){ // Note 3
                return false;
            }
            pageSum = A[i]; // Assigning first book to the new student.
        }
    }
    return true;
}

int books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    
    int start = A[0];
    int end = 0;
    int sum = 0;
    for(int i=0; i<A.size(); i++){
        end = end + A[i];
        start = min(start, A[i]);
    }// search space is between start to end
    
    int ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(isPossible(A, B, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}



/*
Note 4: Days are more than the number of chapters. Since he studies and completes chapter in a day, cannot 
        equally distributes among all the days. Hence false.

*/
// Coding Ninjas
bool isPossible(vector<int> &A, int days, long long mid){
    int daysCount = 1;
    long long int totalTime = 0;
    
    for(int i=0; i<A.size(); i++){
        if((totalTime + A[i]) <= mid){
            totalTime += A[i];
        }else{
            daysCount++;
            if(daysCount > days || A[i] > mid){
                return false;
            }
            totalTime = A[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int days, int chapters, vector<int> time) {
    if(days > time.size()) return -1; // Note 4:
    
    long long start = 0;
    long long end = 0;
    for(int i=0; i<chapters; i++){
        end = end + time[i];
    } // Searching space is between start and end.
    
    long long ans = -1;
    long long mid = start + (end-start)/2;
    while(start <= end){
        if(isPossible(time, days, mid)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    
    return ans;
}

