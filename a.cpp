

#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<climits>
using namespace std;


int zAlgorithm(string haystack, string needle, int h, int n)
{     
    string totalStr = needle + '$' + haystack;
    int len = totalStr.length();
    vector<int> z(len);
    
    z.push_back(0);
    int l = 0;
    int r = 0;
    for(int k=1; k<len; k++){
        if(k > r){
            l=r=k;
            while(r < len && totalStr[r] == totalStr[r-l]){
                r++;
            }
            z[k] = r-l;
            r--;
        }
        else{ // k < r
            if((k+z[k-l]) <= r){
                z[k] = z[k-l];
            }
            else{
                l=k;
                while(r < len && totalStr[r] == totalStr[r-l]){
                    r++;
                }
                z[k] = r-l;
                r--;
            }
        }
    }
    
    int occurence = 0;
    for(int k=n; k<z.size(); k++){
        if(z[k] == n){
            occurence++;
        }
    }
    return occurence;
}

int main(){
    cout << zAlgorithm("ababa", "ab", 5, 2);
} 