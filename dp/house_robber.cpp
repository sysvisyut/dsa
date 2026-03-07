#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // int helper(int ind,vector<int>& nums,vector<int>& dp){
    //     if(ind == nums.size()-1){
    //         return dp[ind] = nums[nums.size()-1];
    //     }
    //     else if( ind >= nums.size()) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     int not_take = 0+ helper(ind+1,nums,dp);
    //     int take = nums[ind]+ helper(ind+2,nums,dp);

    //     return dp[ind] = max(take,not_take);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,0);

        dp[n] = 0;
        dp[n+1] = 0;

        for(int ind=n-1;ind>=0;ind--) {
            

            int not_take = 0+ dp[ind+1];
            int take = nums[ind]+ dp[ind+2];

            dp[ind] = max(take,not_take);
        }
        return dp[0];
    }
};