#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;

        for(int ind =i;ind <=j;ind++){
            int cost = (nums[i-1]*nums[ind]*nums[j+1])+helper(i,ind-1,nums,dp)+helper(ind+1,j,nums,dp);

            maxi = max(maxi,cost);
        }

        return dp[i][j] = maxi;
    }

    // bottom up approach
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n+3,vector<int>(n+3,0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i > j) continue;

                int maxi= INT_MIN;
                for(int k = i; k<=j;k++){
                    
                    int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+ dp[k+1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};
