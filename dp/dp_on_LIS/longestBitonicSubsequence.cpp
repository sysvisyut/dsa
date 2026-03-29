#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {

  public:
  /*logic: apply lis for the normal array and also apply lis from reverse
  array, now compare the dp array of each we add both -1 for the common element
  to get the longest bitonic subsequence in that index, return the max out of all*/
    
    void lis(int n, vector<int> &nums,vector<int>& dp){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
    }
    int longestBitonicSequence(int n, vector<int> &nums){
        // code here
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        lis(n,nums,dp1);
        
        for(int i= n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i],dp2[j]+1);
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp1[i] > 1 && dp2[i] > 1){
                ans = max(ans,dp1[i]+dp2[i]-1);
            }
        }
        return ans;
    
    }
};
