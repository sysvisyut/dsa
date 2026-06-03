#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
public:
    struct trieNode{
        bool isEnd;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;

        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(char c: word){
            if(crawler->children[c-'a'] == NULL){
                crawler->children[c-'a'] = getNode();
            }
            crawler = crawler->children[c-'a'];
        }
        crawler->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;
        int i =0;
        for(;i<word.size();i++){
            if(crawler->children[word[i]-'a'] == NULL){
                return false;
            }
            crawler = crawler->children[word[i]-'a'];
        }

        return crawler->isEnd;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i =0;
        for(;i<prefix.size();i++){
            if(crawler->children[prefix[i]-'a'] == NULL){
                return false;
            }
            crawler = crawler->children[prefix[i]-'a'];
        }
        return i== prefix.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */