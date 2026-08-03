#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <numeric>
using namespace std;


class Solution {
public:
    int n;

    int helper(int i, int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ch1 = nums[i]+ min(helper(i+2,j,nums,dp),helper(i+1,j-1,nums,dp));
        int ch2 = nums[j]+ min(helper(i+1,j-1,nums,dp), helper(i,j-2,nums,dp));

        int maxi = max(ch1, ch2);

        return dp[i][j] = maxi;
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int tot = accumulate(nums.begin(),nums.end(),0);
        int p1 =  helper(0,n-1,nums,dp);
        int p2 = tot-p1;

        return p1>=p2;
    }
};