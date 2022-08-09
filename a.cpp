

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
#include<queue>
#include <stdlib.h> 
#include<cstdlib>
using namespace std;


bool isZero(string temp){
    for(int i=0; i<temp.length(); i++){
        if(temp[i] != 0) return false;
    }
    return true;
}

queue<string> removeDots(string str){
    queue<string> q;
    string temp = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] == '.'){
            if(isZero(temp)) q.push("0");
            else q.push(temp);
            temp = "";
        }else{
            temp = temp + str[i];
            if(i == str.length()-1){
                if(isZero(temp)) q.push("0");
                else q.push(temp);
            }
        }
    }
    return q;
}

int compareVersions(string a, string b) 
{
    queue<string> first = removeDots(a);
    queue<string> second = removeDots(b);
    
    string firstStr, secondStr;
    while(first.size() && second.size()){
        firstStr = first.front();
        first.pop();
        secondStr = second.front();
        second.pop();
        
        if(firstStr > secondStr) return 1;
        else if(secondStr > firstStr) return -1;
    }
    
    if(first.size()){
        while(first.size()){
            firstStr = first.front();
            first.pop();   
            cout << isZero(firstStr) << " -- ";
            if(!isZero(firstStr)) return 1;
        }
        return 0;
    }
    if(second.size()){
        while(second.size()){
            secondStr = second.front();
            second.pop();   
            if(!isZero(secondStr)) return -1;
        }
        return 0;
    }
    else return 0;
}

int main(){
    cout << compareVersions("1.0.0", "1");
} 