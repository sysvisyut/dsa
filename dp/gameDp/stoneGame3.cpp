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
    int helper(int i, vector<int>& nums,vector<int>& dp){

        if(i>= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        
        int take = 0;
        int ans = INT_MIN;

        for(int j=0;j<3 && i+j< n;j++){
            take+= nums[i+j];

            ans = max(ans, take- helper(i+j+1,nums,dp));
        }


        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& nums){
        n = nums.size();
        vector<int> dp(n+1,-1);
        int score = helper(0,nums,dp);


        if(score > 0) return "Alice";
        else if(score < 0) return "Bob";

        else return "Tie";
    }
};