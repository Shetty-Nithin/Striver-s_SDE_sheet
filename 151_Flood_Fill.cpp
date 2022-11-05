// Link : https://www.codingninjas.com/codestudio/problems/1089687?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Link : https://leetcode.com/problems/flood-fill/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void color(vector<vector<int>> &image, int x, int y, int newColor, int oldColor, int row, int col){
    if(x >= row || x < 0 || y >= col || y < 0) {
        return;
    }  
    if(image[x][y] != oldColor){
        return;
    }
    
    image[x][y] = newColor;
    
    color(image, x+1, y, newColor, oldColor, row, col);
    color(image, x-1, y, newColor, oldColor, row, col);
    color(image, x, y+1, newColor, oldColor, row, col);
    color(image, x, y-1, newColor, oldColor, row, col);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{   
    int oldColor = image[x][y];
    if(oldColor == newColor){
        return image;
    }
    
    int row = image.size();
    int col = image[0].size();
    color(image, x, y, newColor, oldColor, row, col);
    
    return image;
}