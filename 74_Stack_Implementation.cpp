/*
Implementation of Stack.
*/

#include<iostream>
#include<stack>
using namespace std;


// approach 1 : using array.

// class Stack {
//     public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int element){
//         if(abs(size - top) > 1){
//             top++;
//             arr[top] = element;
//         }else{
//             cout << "Stack overflow" << endl;
//         }
//     }

//     void pop(){
//         if(top >= 0){
//             top--;
//         }else{
//             cout << "Stack underflow" << endl;
//         }
//     }

//     int peek(){
//         if(top >= 0){
//             return arr[top];
//         }else{
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }else{
//             return false;
//         }
//     }
// };



// approach 2 : using linked list.

struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack {
    private:
    Node* top;
    int size;

    public:
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);

        if(top == NULL){
            top = newNode;
            size++;
        }else{
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }else{
            Node* deletNode = top;
            top = top->next;
            delete deletNode;
            size--;
        }
    }

    int peek(){
        if(top == NULL){
            return -1;
        }else return top->data;
    }

    bool isEmpty(){
        if(top == NULL) return true;
        return false;
    }

    void print(){
        Node* t = top;
        cout << "Stack : ";
        
        while(t != NULL){
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << endl;
    }
};


int main(){
    // Stack* s = new Stack(5);
    // s->push(10);
    // s->push(20);
    // s->push(30);
    // cout << s->peek() << endl;
    // s->pop();
    // cout << s->peek() << endl;

    Stack* s2 = new Stack();
    s2->push(50);
    cout << s2->isEmpty() << endl;
    s2->push(50);
    s2->push(50);
    s2->push(50);
    s2->push(60);
    s2->print();
    cout << s2->peek() << endl;
    s2->pop();
    cout << s2->peek() << endl;
    s2->pop();
    s2->pop();
    s2->pop();
    s2->pop();
    s2->pop();
    cout << s2->peek() << endl;
    cout << s2->isEmpty() << endl;
    s2->print();
}



// Striver's sheet problem : https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    sort(arr.begin(), arr.end());
    vector<int> ans;
    
    for(int i=0; i<queries.size(); i++){
        int ithAns = -1;
        for(int j=0; j<arr.size(); j++){
            if(arr[j] > queries[i][1]) break;
            ithAns = max(ithAns, queries[i][0]^arr[j]);
        }
        ans.push_back(ithAns);
    }
    
    return ans;
}