#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n,-1);

        int maxi = 1;
        int prevIdx = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] ==0){
                    
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                    if(dp[i] > maxi){
                        maxi = dp[i];
                        prevIdx = i;
                    }
                }
            }
        }

        vector<int> res;
        while(prevIdx != -1){
            res.push_back(nums[prevIdx]);
            prevIdx = prev[prevIdx];
        }

        return res;
    }
};