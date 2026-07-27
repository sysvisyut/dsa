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
    int dp[501];

    // int helper(int i, vector<int>& arr, int k){
    //     if(i == arr.size()){
    //         return 0;
    //     }

    //     if(dp[i] != -1) return dp[i];

    //     int maxi = INT_MIN;
    //     int maxSum = INT_MIN;
    //     int len = 0;
    //     int currSum = 0;

    //     for(int j=i;j< min(n,i+k);j++){
    //         len++;
    //         maxi = max(maxi, arr[j]);

    //         currSum = (len*maxi)+ helper(j+1,arr,k);

    //         maxSum = max(maxSum, currSum);
    //     }

    //     return dp[i] = maxSum;

    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        n = arr.size();
        memset(dp,0,sizeof(dp));

        for(int i=n-1;i>=0;i--){

            int maxi = INT_MIN;
            int maxSum = INT_MIN;
            int len = 0;
            int currSum = 0;

            for(int j=i;j< min(n,i+k);j++){
                len++;
                maxi = max(maxi, arr[j]);

                currSum = (len*maxi)+ dp[j+1];

                maxSum = max(maxSum, currSum);
            }

            dp[i] = maxSum;

        }
         
        return dp[0];
      
    }
};