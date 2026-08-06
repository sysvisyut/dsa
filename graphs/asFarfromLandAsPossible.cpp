#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int maxDistance(vector<vector<int>>& grid) {
        // push every one to queue and apply bfs to each, if the cell is already visited keep the maximum of 1+level,dis[i][j] 

        int n = grid.size();

        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        int maxi = INT_MIN;

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }

        if(q.size() == 0 || q.size() == n*n) return -1;
        int lvl = 0;
        
        while(!q.empty()){
            int sz = q.size();
            lvl++;

            for(int i=0;i<sz;i++){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(int j=0;j<4;j++){
                    int nx = x+dx[j];
                    int ny = y+dy[j];

                    if(nx >=0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 0){

                        if(dis[nx][ny] > lvl){
                            dis[nx][ny] = lvl;
                            maxi = max(maxi,dis[nx][ny]);
                            q.push({nx,ny});
                        }
                    }
                }
            }

        }

        return maxi;

    }
};