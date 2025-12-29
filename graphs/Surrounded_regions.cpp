#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        //vector<vector<char>> ans(row,vector<char>(col));
        vector<vector<int>> vis(row,vector<int>(col));

        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                board[i][0] ='O';
                vis[i][0] = 1;
            }
        }
        for(int i=1;i<col;i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                board[0][i] ='O';
                vis[0][i] = 1;
            }
        }
         for(int i=1;i<row;i++){
            if(board[i][col-1] == 'O'){
                q.push({i,col-1});
                board[i][col-1] ='O';
                vis[i][col-1] = 1;
            }
        }
         for(int i=1;i<col-1;i++){
            if(board[row-1][i] == 'O'){
                q.push({row-1,i});
                board[row-1][i] ='O';
                vis[row-1][i] = 1;
            }
        }

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow<row && nrow >=0 && ncol <col && ncol>=0 && board[nrow][ncol]=='O' &&
                !vis[nrow][ncol]){
                    board[nrow][ncol] = 'O';
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};