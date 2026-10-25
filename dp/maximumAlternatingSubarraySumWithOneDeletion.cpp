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

    ll helper(int i, int parity, int done, int started, vector<int>& nums,vector<vector<vector<vector<ll>>>>& dp){

        if(i == nums.size()) return started ? 0 : LLONG_MIN;

        if(dp[i][parity][done][started] != LLONG_MIN) return dp[i][parity][done][started];

        ll ans = LLONG_MIN;


        if(!started){ //subarray has not started yet

            ans = max(ans, helper(i+1,0,0,0,nums,dp)); // skip this element 

            ans = max(ans, nums[i]+helper(i+1,1,0,1,nums,dp)); //start the subarray with the curr element
        }

        else{
            ans = 0; // end the already started subarray here

            ans = max(ans, (parity ? -1LL: 1LL)*nums[i]+helper(i+1,parity^1,done,1,nums,dp)); // continue the subarray by taking this element

            if(!done){ // deletion is not done do it and continue, parity will remain the same since this element is skipped next element will carry forward the parity of this

                ans = max(ans, helper(i+1,parity,1,1,nums,dp));
            }
        }

        return dp[i][parity][done][started] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<vector<vector<ll>>>> dp(n,vector<vector<vector<ll>>>(2,vector<vector<ll>>(2,vector<ll>(2,LLONG_MIN))));

        return helper(0,0,0,0,nums,dp);

    }
};