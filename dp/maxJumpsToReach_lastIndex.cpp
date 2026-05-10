#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

/*LOGIC: start with the first index, and run a for loop to check the reachability for every index, if the index
if valid the make the jump i.e add 1 and call the function for the next valid index, keep storing the max value 
for every jump and return the final res*/

class Solution {
public:
    // int helper(int i,vector<int>& nums, int t,vector<int>& dp){
    //     int n = nums.size();
    //     if(i == n-1){
    //         return 0;
    //     }

    //     if(dp[i] != INT_MAX) return dp[i];
    //     int res = INT_MIN;
        
    //     for(int j=i+1;j<n;j++){
    //         if(abs(nums[i]-nums[j]) <= t){
    //             int temp = 1+ helper(j, nums,t,dp);
    //             res = max(res,temp);
    //         }
    //     }

    //     return dp[i] = res;

    // }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MIN);
        dp[n-1] = 0;
    
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j]) <= target && dp[j] != INT_MIN){
                    int temp = 1+ dp[j];
                    dp[i] = max(dp[i],temp);
                }
            }
        }
        return (dp[0]< 0)? -1 : dp[0];
    }
};