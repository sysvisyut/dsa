#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int n;
    
    int helper(int i,int j, vector<int>& piles,vector<vector<int>>& dp){
        if(i == j) return piles[i];
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        

        int ch1 = piles[i]-helper(i+1,j,piles,dp);
        int ch2 = piles[j]-helper(i,j-1,piles,dp);

        return dp[i][j] = max(ch1,ch2);
        
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int score = helper(0, n-1,piles,dp);

        return score >0;
    }
};