// Link : https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class mHeap {
    private:
        int arr[10000];
        int size;
    public:
        mHeap (){
            arr[0] = -1;
            size = 0;
        }

        void push(int val){
            size++;
            int index = size;
            arr[index] = val;
            
            int parent;
            while(index > 1){
                parent = index/2;
                if(arr[parent] > arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else return;
            }
        }

        int pop(){
            if(size == 0) return -1;
            int deleteElement = arr[1];
            arr[1] = arr[size];
            size--;
            
            int i=1;
            while(i <= size){
                int leftNodeInd = 2*i;
                int rightNodeInd = 2*i + 1;
                int smaller = i;
                
                if(leftNodeInd <= size && arr[leftNodeInd] < arr[smaller]){
                    smaller = leftNodeInd;
                }
                if(rightNodeInd <= size && arr[rightNodeInd] < arr[smaller]){
                    smaller = rightNodeInd;
                }
                if(i == smaller) break;
                else {
                    swap(arr[i], arr[smaller]);
                    i = smaller;
                }
            }
            return deleteElement;
        }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    mHeap mH;
    vector<int> ans;
    
    for(auto it : q){
        if(it[0] == 0){
            mH.push(it[1]);
        }else{
            ans.push_back(mH.pop());
        }
    }
    
    return ans;
}