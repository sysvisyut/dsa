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
    int n,m;

    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr<0 || nr>=n || nc<0 || nc>=m || vis[nr][nc] || grid[nr][nc] != 1){
                continue;
            }
            dfs(nr,nc,vis,grid);
        }
    }

    int countIslands(vector<vector<int>>& grid){
        int cnt = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == false && grid[i][j] == 1){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        
        
        n = grid.size();
        m = grid[0].size();


        int islands = countIslands(grid);

        if(islands > 1 || islands == 0){
            return 0;
        }
        else{

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]){

                        grid[i][j] = 0;

                        int cnt = countIslands(grid);

                        if(cnt > 1 || cnt ==0) return 1;

                        grid[i][j] = 1;
                    }
                }
            }
        }

        return 2;


    }
};