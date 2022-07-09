// Link : https://leetcode.com/problems/lfu-cache/submissions/


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Node {
  public:
    int key, val, count;
    Node* next;
    Node* prev;

    Node (int key, int val){
        this->key = key;
        this->val = val;
        this->count = 1;
    }
};


class List {
    public:
    int size;
    Node* head;
    Node* tail;
    
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    
    void deleteNode(Node* existingNode){
        Node* existNext = existingNode->next;
        Node* existPrev = existingNode->prev;
        existPrev->next = existNext;
        existNext->prev = existPrev;
        size--;
    }
};



class LFUCache {
    map<int , Node*> keyNode;
    map<int, List*> freqList;
    int maxCacheSize;
    int minFreq;
    int currCacheSize;
    
public:
    LFUCache(int capacity) {
        maxCacheSize = capacity;
        minFreq = 0;
        currCacheSize = 0;
    }
    
    void updateFreqList(Node* node){
        keyNode.erase(node->key);
        freqList[node->count]->deleteNode(node);
        if(node->count == minFreq && freqList[node->count]->size == 0){
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        if(freqList.find(node->count+1) != freqList.end()){
            nextHigherFreqList = freqList[node->count+1];
        }
        node->count += 1;
        nextHigherFreqList->addNode(node);
        freqList[node->count] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int res = node->val;
            updateFreqList(node);
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(maxCacheSize == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
        }
        else{
            if(currCacheSize == maxCacheSize){
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->deleteNode(list->tail->prev);
                currCacheSize--;
            }
            currCacheSize++;
            
            minFreq = 1;
            List* listFreq = new List();
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq->addNode(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */