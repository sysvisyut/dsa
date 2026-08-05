#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    int n,m;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    int check(int i,int j,vector<vector<int>>& grid){
        
        int cnt = 4;
        
        for(int k=0;k<4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];

            if(nr>=0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 1){
                cnt--;
            }
            
        }
        return cnt;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;
        
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 1){
                    int val = check(i,j,grid);
                    ans+=val;
                }
            }
        }

        return ans;
    }
};