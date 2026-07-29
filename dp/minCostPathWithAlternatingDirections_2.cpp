#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
typedef long long ll;

    int N,M;

    bool isIntermediate(int i, int j, int m, int n){
        return !(i==0 && j==0 || i == m-1 && j==n-1);
    }

    ll helper(int i, int j,vector<vector<int>>& waitCost,vector<vector<ll>>& dp){

        if(i == M || j==N){
            return LLONG_MAX;
        }
        if(i == M-1 && j == N-1){
            return M*N;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        ll entranceCost = (i+1)*(j+1);

        ll down = helper(i+1,j,waitCost,dp);
        ll right = helper(i,j+1,waitCost,dp);

        ll mini = entranceCost+min(down,right);

        if(isIntermediate(i,j,M,N)){
            mini+= waitCost[i][j];
        }

        return dp[i][j] = mini;

        
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        M=m;
        N=n;
        vector<vector<ll>> dp(m, vector<ll>(n,-1));
        
        return helper(0,0,waitCost,dp);
    }
};