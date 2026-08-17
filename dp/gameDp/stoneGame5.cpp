#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> pre;
    int dp[501][501];

    int helper(int l, int r,vector<int>& nums){

        if(l >= r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        int score = 0;
        for(int i =l;i<=r-1;i++){
            int leftSum = pre[i] - (l-1 >=0 ? pre[l-1]: 0);
            int rightSum = pre[r]-pre[i];
    

            if(leftSum > rightSum){
                score = max(score,rightSum+helper(i+1,r,nums));
            }
            else if(rightSum > leftSum){
                score = max(score,leftSum+helper(l,i,nums));
            }
            else{
                score = max(score, max(leftSum+helper(i+1,r,nums),rightSum+helper(l,i,nums)));
            }
            
        }
        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& nums) {

        int n = nums.size();

        memset(dp,-1, sizeof(dp));

        pre.resize(n);
        pre[0] = nums[0];

        for(int i=1;i<n;i++){
            pre[i] = nums[i]+pre[i-1];
        }


        return helper(0,n-1,nums);
        
    }
};