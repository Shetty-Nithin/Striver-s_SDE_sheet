// Link : https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isValid(string temp, vector<string> &dictionary){
    for(string st : dictionary){
        if(st.compare(temp) == 0){
            return true;
            break;
        }
    }
    return false;
}

void solve(string &s, vector<string> &dictionary, vector<string> &collection, int index, string &sentence){
    if(index == s.length()){
        collection.push_back(sentence);
        return;
    }
    
    for(int i=index; i<s.length(); i++){
        string temp = s.substr(index, i-index+1);
        
        if(isValid(temp, dictionary)){
            string backup = sentence;
            sentence += temp + " ";
            solve(s, dictionary, collection, i+1, sentence); // i+1 nor index+1
            sentence = backup;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    vector<string> collection;
    string sentence;
    solve(s, dictionary, collection, 0, sentence);
    
    return collection;
}