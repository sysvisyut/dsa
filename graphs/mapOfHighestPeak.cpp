#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        vector<vector<int>> vis(row,vector<int>(col,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[r][c] = dis;

            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow >=0 && nrow <row && ncol >=0 && ncol <col && vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }

        }

        return ans;
    }
};