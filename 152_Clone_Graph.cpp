// Link : https://leetcode.com/problems/clone-graph/description/
// Link : https://www.codingninjas.com/codestudio/problems/1103394?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    Node* cloneGraphHelper(Node* node, unordered_map<Node*, Node*> &clone){
        Node* firstNode = new Node(node->val);
        clone[node] = firstNode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* nbr : curr->neighbors){
                if(clone.find(nbr) == clone.end()){ // nbr is not present in the unordered_map
                    clone[nbr] = new Node(nbr->val, {});
                    q.push(nbr);
                }

                clone[curr]->neighbors.push_back(clone[nbr]);
            }
        }

        return firstNode;
    }

public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> clone;
        return cloneGraphHelper(node, clone);
    }
};