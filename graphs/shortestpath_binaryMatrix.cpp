#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        if (grid[0][0] == 1 || grid[r-1][c-1] == 1) return -1;

        vector<vector<int>>dis(r,vector<int>(c,1e9));
        dis[0][0] = 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == r-1 && col == c-1) return dist;

            for(int drow = -1;drow<=1;drow++){
                for(int dcol= -1;dcol<=1;dcol++){
                    int nrow = row+drow;
                    int ncol = col+dcol;
                    if(nrow >=0 && nrow <r && ncol>=0 && ncol <c && grid[nrow][ncol] == 0){
                        if(dist+1 < dis[nrow][ncol]){
                            dis[nrow][ncol] = dist+1;
                            q.push({dist+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }

        return -1;

    }
};