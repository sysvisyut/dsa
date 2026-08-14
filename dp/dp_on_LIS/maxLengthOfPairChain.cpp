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
    int dp[1003][1003];
    int helper(int i, int prev,vector<vector<int>>& pairs){
        if(i >= n){
            return 0;
        }

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0;

        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1+helper(i+1,i,pairs);
        }

        int skip = helper(i+1,prev,pairs);

        return dp[i][prev+1] = max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        n = pairs.size();
        auto lambda = [&](auto& a,auto& b){

            if(a[0] == b[0]){
                return a[1] < b[1];
            }

            return a[0] < b[0];
        };
        sort(pairs.begin(),pairs.end(),lambda);
        memset(dp, -1, sizeof(dp));
        return helper(0,-1,pairs);  
    }
};