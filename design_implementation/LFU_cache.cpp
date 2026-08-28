#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int,list<vector<int>>::iterator> mp; //key-> address
    map<int, list<vector<int>>> frq; //counter -> {key,value,counter}

    LFUCache(int capacity) {
        cap = capacity;
        size=0;
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = *(mp[key]);

        int val = vec[1];
        int f = vec[2];

        frq[f].erase(mp[key]);

        if(frq[f].empty()){
            frq.erase(f);
        }
        f++;

        frq[f].push_front({key,val,f});

        mp[key] = frq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        auto vec = (*(mp[key])); //{key,value counter}

        int val = vec[1];

        makeMostFrequentlyUsed(key);

        return val;

    }
    
    void put(int key, int val) {
        if(cap == 0) return;

        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key]));

            vec[1] = val;

            makeMostFrequentlyUsed(key);
        }
        else if(size < cap){
            size++;

            frq[1].push_front(vector<int>({key,val,1}));
            mp[key] = frq[1].begin();

        }
        else{ //remove LFU if tie remove LRU

            auto &curr_list = frq.begin()->second;  //returns the DLL with least counter val

            int keyToDelete = (curr_list.back())[0];

            curr_list.pop_back();

            if(curr_list.empty()){
                frq.erase(frq.begin()->first); //map.erase(key)
            }
            frq[1].push_front(vector<int>({key,val,1}));

            mp.erase(keyToDelete);

            mp[key] = frq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */