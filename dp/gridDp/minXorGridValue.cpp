#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    
    bool helper(int i,int j,int tar,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i >= m || j >= n) return false;
        if(i == m-1 && j == n-1){
            return tar == grid[i][j];
        }

        if(dp[i][j][tar] != -1) return dp[i][j][tar];

        int ntar = tar^grid[i][j];

        bool ok = helper(i+1,j,ntar,grid,dp) || helper(i,j+1,ntar,grid,dp);


        return dp[i][j][tar] = ok;
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));

        for(int tar =0;tar<1024;tar++){
            if(helper(0,0,tar,grid,dp)){
                return tar;
            }
        }
        return 0;
    }
};