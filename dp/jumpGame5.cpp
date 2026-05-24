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
    // int helper(int idx,vector<int>& arr, int d,vector<int>& dp){
    //     int jumps = 1;
    //     int curr = arr[idx];
        
    //     if(dp[idx] != -1) return dp[idx];

    //     for(int i=1;i<=d;i++){
    //         if(idx-i >=0 && arr[idx-i] >= curr) break;
    //         if(idx-i >= 0 && arr[idx-i] < curr){
    //             jumps = max(jumps,1+helper(idx-i, arr, d,dp));
    //         }
            
    //     }
    //      for(int i=1;i<=d;i++){
    //         if(idx+i <n && arr[idx+i] >= curr) break;
    //         if(idx+i < n && arr[idx+i] < curr){
    //             jumps = max(jumps,1+helper(idx+i, arr, d,dp));
    //         }
            
    //     }


    //     return dp[idx]= jumps;

    // }
    int maxJumps(vector<int>& arr, int d) {
        /*->try possible jumps from every possible index, and finally return the most optimal index
        */
        n = arr.size();
        vector<int> dp(n,1);

        vector<pair<int,int>> nums; // stores {arr[i],i};

        for(int i=0;i<n;i++){
            nums.push_back({arr[i],i});
        }


        sort(nums.begin(),nums.end());


        for(auto it: nums){
            int val = it.first;
            int i = it.second;

            for(int j=i-1;j >= max(0, i-d);j--){
                if(arr[j] >= val) break;

                dp[i]= max(dp[i],1+dp[j]);
            }
            for(int j = i+1;j<=min(n-1, i+d);j++){
                if(arr[j] >= val) break;

                dp[i] = max(dp[i],1+dp[j]);
            }

        }

        int ans = *max_element(dp.begin(),dp.end());
        
        return ans;
    }
};