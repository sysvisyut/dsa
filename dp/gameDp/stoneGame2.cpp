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
    int dp[2][101][101];
    
    int helper(int player,int i,int m,vector<int>& piles){
        if(i >= n){
            return 0;
        }
        if(dp[player][i][m] != -1) return dp[player][i][m];
        int stones= 0;
        int ans = (player== 1 ? -1: INT_MAX);
        
        for(int x=1;x<= min(2*m,n-i);x++){
            stones+=piles[i+x-1];

            if(player == 1){ //alice since this function calculates max stones possible for alice it adds the stones till now to the answer
                ans = max(ans, stones+helper(0,i+x,max(m,x),piles));
            }
            else{ //bob
                ans = min(ans,helper(1,i+x,max(m,x),piles));
            }
        }

        return dp[player][i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1, sizeof(dp));

        return helper(1,0,1,piles);
    }
};