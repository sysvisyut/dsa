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
#include <sstream>

using namespace std;


class Solution {
public:
    struct trieNode{
        string w;
        bool isEnd;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        
        for(int i=0;i<26;i++){
            newNode->children[i] =NULL;
        }

        return newNode;
    }
    trieNode* root;
    
    void insert(string &word){
        trieNode* crawler = root;
        for(char c: word){
            if(crawler->children[c-'a'] == NULL){
                crawler->children[c-'a'] = getNode();
            }
            crawler = crawler->children[c-'a'];
        }
        crawler->isEnd = true;
    }

    string search(string& word){
        trieNode* crawler = root;
        int i=0;
        for(;i<word.size();i++){
            if(crawler->children[word[i]-'a'] == NULL){
                return word;
            } // the curr word of sentence doesnt have any prefix
            crawler = crawler->children[word[i]-'a'];
            if(crawler->isEnd){
                return word.substr(0,i+1);
            }
        }

        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        root = getNode();
        for(string &s: dictionary){
            insert(s);
        }

        stringstream ss(sentence);
        string word;
        string ans;

        while(ss >> word){
            if(!ans.empty()){
                ans+=" ";
            }
            ans+=search(word);
        }

        return ans;


    }
};