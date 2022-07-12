

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> symbols{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int num = 0;
    
    for(int ch=0; ch<s.length(); ch++){
        num += symbols[s[ch]];
    }
    
    return num;
}

int main(){
    
    cout << romanToInt("III") << endl;
    return 0;
} 