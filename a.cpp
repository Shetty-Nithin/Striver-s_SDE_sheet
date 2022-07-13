

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;


int repeatedStringMatch(string a, string b) {
    
    int count = 1;
    string repeatedA = a;

    int compareLen = 0;
    int i = 0;
    int j = 0;
    while(j < b.length() && i < repeatedA.length()){
        if(b[j] == repeatedA[i]){
            compareLen++;
            i++;
            j++;
            
            if(repeatedA.length()-i < b.length()-j){
                repeatedA = repeatedA + a;
                count++;
            }
            
        }else{
            i = i-j+1;
            j = 0;
            compareLen = 0;
        }
    }

    if(compareLen == b.length()){
        return count;
    }
    return -1;
}

int main(){
   cout << repeatedStringMatch("abcabcabcabc", "abac");
} 