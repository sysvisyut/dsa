#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>

using namespace std;

class Solution {
public:
    struct TrieNode{
        bool end;
        TrieNode* children[26];
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->end = false;
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    TrieNode* root;

    void insert(string &w){
        TrieNode* crawler = root;
        for(char c: w){
            if(crawler->children[c-'a'] == NULL){
                crawler->children[c-'a'] = getNode();
            }
            crawler = crawler->children[c-'a'];
        }
        crawler->end = true;

    }

    bool isValid(string &w){
        TrieNode* crawler = root;

        for(char c: w){
            if(crawler->children[c-'a'] == NULL){
                return false;
            }
           
            crawler = crawler->children[c-'a'];
            if(crawler->end == true){
                return true;
            }
        }
        return false;
    }
    int prefixCount(vector<string>& words, string pref) {
        root = getNode();

        insert(pref);

        int ans = 0;
        for(string &w : words){
            if(isValid(w)){
                ans++;
            }
        }

        return ans;
    }
};