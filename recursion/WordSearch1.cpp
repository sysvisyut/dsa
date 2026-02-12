#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int dr[4] = {-1,0,+1,0};
    int dc[4] = {0,+1,0,-1};
    bool find(int i, int j, int idx, string word,int r, int c,vector<vector<char>>& board){
        if(idx == word.size()) return true;
        if(i>=r || i<0 || j>=c || j<0 || board[i][j] == '$') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for(int k=0;k<4;k++){
            if(find(i+dr[k],j+dc[k],idx+1,word,r,c,board)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j] == word[0] && find(i,j,0,word,r,c,board)){
                    return true;
                }
            }
        }
        return false;
    }
};