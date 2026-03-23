#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool check(int row, int col,vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(row >=0 && row <m && col>=0 && col <n){
            return true;
        }
        return false;
    }
    void bfs(int r, int c,vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,+1,0,-1};

        queue<pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nr = x+dr[i];
                int nc = y+dc[i];

                if(check(nr,nc,grid) && vis[nr][nc] ==0 && grid[nr][nc] == '1'){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i,j,grid,vis);
                    cnt++; //no of time bfs is called gives the no of islands
                }
            }
        }

        return cnt;
    }
};