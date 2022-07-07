// Link : https://leetcode.com/problems/lru-cache/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    public:
    Node (int _key, int _val) {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> u_map;
    
    public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* existingNode){
        Node* existPrev = existingNode->prev;
        Node* existNext = existingNode->next;
        existPrev->next = existNext;
        existNext->prev = existPrev;
    }
    
    int get(int key) {
        if(u_map.find(key) != u_map.end()){
            Node* resNode = u_map[key];
            int res = resNode->val;
            u_map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            u_map[key] = head->next;
            
            return res;
        }    
        return -1;
    }
    
    void put(int key, int value) {
        if(u_map.find(key) != u_map.end()){
            Node* existingNode = u_map[key];
            u_map.erase(key);
            deleteNode(existingNode);
        }
        if(u_map.size() == cap){
            u_map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key, value));
        u_map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */