#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                grid[i][0] = 0;
            }
        }
        for(int i=1;i<col;i++){
            if(grid[0][i] == 1){
                q.push({0,i});
                grid[0][i]=0;
            }
        }
        for(int i=1;i<row;i++){
            if(grid[i][col-1] == 1){
                q.push({i,col-1});
                grid[i][col-1]=0;
            }
        }
        for(int i=1;i<col-1;i++){
            if(grid[row-1][i] == 1){
                q.push({row-1,i});
                grid[row-1][i]=0;
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

                if(nrow>=0 &&nrow <row &&ncol>=0 &&ncol <col && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = 0;
                }
            }
        }

        int ans=0;

        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};