

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

void sort(stack<int> &stack, int &store){
    if(stack.empty() || stack.top() < store){
        stack.push(store);
        return;
    }
    
    int store_2 = stack.top();
    stack.pop();
    sort(stack, store);
    stack.push(store_2);
}

void solve(stack<int> &stack){
    if(stack.size() == 1){
        return;
    }
    
    int store = stack.top();
    stack.pop();
    solve(stack);
    
    sort(stack, store);
}

void sortStack(stack<int> &stack)
{
	solve(stack);
}

int main(){
    stack<int> stack;
    stack.push(5);
    stack.push(-2);
    stack.push(9);
    stack.push(-7);
    stack.push(3);
    sortStack(stack);

    while(stack.size()){
        cout << stack.top();
        stack.pop();
    }
}