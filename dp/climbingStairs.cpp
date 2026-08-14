#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int dp[46];
    int helper(int n){
        if(n == 0){
            return dp[n] = 1;
        }
        if(n < 0) return 0;

        if(dp[n] != - 1) return dp[n];

        return dp[n] = helper(n-1)+helper(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};