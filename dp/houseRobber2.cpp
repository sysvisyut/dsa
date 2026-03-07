#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int helper(int i, vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(i== n-1){
            return dp[i] = nums[n-1];
        }
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take  = nums[i]+helper(i+2,nums,dp);
        int not_take = 0+helper(i+1,nums,dp);

        return dp[i] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(n+2,-1);
        vector<int> dp2(n+2,-1);

        int ans1 = helper(0,temp1,dp1);
        int ans2 = helper(0,temp2,dp2);

        return max(ans1,ans2);
    }
};