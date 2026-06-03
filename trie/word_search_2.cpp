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
    vector<string> res;
    int m,n;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    struct trieNode{ // define trie structure
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->word = "";
        
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(trieNode* root, string &word){
        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch-'a'];
        }

        crawler->endOfWord = true;
        crawler->word = word;
    }

    void wordFinder(vector<vector<char>>& board,int i, int j, trieNode* root){
        if(i <0 || i>=m || j<0 || j>=n ) return;

        if(board[i][j] == '$' || root->children[board[i][j]-'a'] == NULL){
            return;
        }
        root = root->children[board[i][j]-'a'];
        if(root->endOfWord == true){
            res.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];

        board[i][j] = '$'; //mark it visited

        for(int k =0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];

            wordFinder(board,ni,nj,root);
        }

        board[i][j] = temp; //mark it unvisited after completing exploration




    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();


        trieNode* root = getNode(); //create root

        //store the words given in the trie
        for(string &word: words){
            insert(root, word);
        }

        // traverse in the trie ds just once and mark all the words that are present
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch = board[i][j];
                if(root->children[ch-'a'] != NULL){
                    wordFinder(board,i,j,root);
                }
            }
        }

        return res;


    }
};