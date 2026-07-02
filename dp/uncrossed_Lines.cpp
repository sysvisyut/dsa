#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int helper(int i, int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){
        if(i>=nums1.size() || j >=nums2.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;

        if(nums1[i] == nums2[j]){
            ans = 1+helper(i+1,j+1,nums1, nums2,dp);
        }
        else{
            ans = max(helper(i+1,j,nums1,nums2,dp),helper(i,j+1,nums1,nums2,dp));
        }

        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return helper(0,0,nums1,nums2,dp);
    }
};