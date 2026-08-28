#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

class LRUCache {
public:
    struct node{
        node* prev;
        node* next;
        int val;
        int key;

        node(int key, int val){
            this->key = key;
            this->val = val;
            prev = nullptr;
            next = nullptr;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int,node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* resnode = mp[key];
            int res = resnode->val;

            deleteNode(resnode); //this key has been used so, move it near to head
            addNode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1; //key was not found in map
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){ // key already exists in the cache.
            node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */