// Link : https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount) 
{
    int availableCoins[9] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int minCoins = 0;
    while(amount >= 1){
        int coin = 0;
        for(int i=0; i<9; i++){
            if(amount >= availableCoins[i]){
                coin = availableCoins[i];
                break;
            }
        }            
        minCoins += amount/coin;
        amount = amount%coin;
    }
    
    return minCoins;
}