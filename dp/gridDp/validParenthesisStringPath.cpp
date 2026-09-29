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

    bool helper(int i, int j, int bal, vector<vector<char>>& grid,vector<vector<vector<int>>>& dp){

        if(i >=n || j>=m) return false;


        if(grid[i][j] == '('){
            bal++;
        }
        else{
            bal--;
        }

        if(bal < 0) return false;
        if(dp[i][j][bal] != -1) return dp[i][j][bal];

        if(i == n-1 && j == m-1){
            return bal == 0;
        }

        return dp[i][j][bal] = helper(i+1,j,bal,grid,dp) || helper(i,j+1,bal,grid,dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1,vector<int>(n+m+1,-1)));

        return helper(0,0,0,grid,dp);
    }
};