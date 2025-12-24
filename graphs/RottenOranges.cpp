#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}); //push all the initially rotten oranges into the queue at time =0
                    vis[i][j] = 2; //mark them as rotten and visited in vis 
                }
                else{
                    vis[i][j] = 0; // if its empty or fresh mark them as not visited
                }
            }
        }
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};
        int tm =0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();
            tm = max(t,tm);

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow <n && nrow>=0 && ncol <m && ncol>=0 && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2; //mark the fresh neighbor oranges as visited & rotted
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;//if in the orange is not visited & rotten but its a fresh orange
                }
            }
        }
        return tm;

    }
};