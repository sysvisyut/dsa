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
    int helper(int idx, vector<int>& nums,vector<int>& dp){
        if(idx == n-1){
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int one = (idx+1 <n)?abs(nums[idx]-nums[idx+1])+helper(idx+1,nums,dp): INT_MAX;
        
        int two = (idx+2 <n)?abs(nums[idx]-nums[idx+2])+helper(idx+2,nums,dp): INT_MAX;
        
        return dp[idx] = min(one, two);
    }
    int minCost(vector<int>& height) {
        // Code here
        n = height.size();
        vector<int> dp(n, -1);
        return helper(0,height,dp);
        
    }
};