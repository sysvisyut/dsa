#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1); // each num is a LIS of Len 1

        int maxi = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};

// most optimal solution using lower_bound , time complexity = O(nlogn)


int lengthOfLIS(vector<int>& nums) {
        
        vector<int> bs;

        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(bs.begin(),bs.end(),nums[i]);

            if(it == bs.end()){ // element greater than everything, so the seq len should increase 
                bs.push_back(nums[i]);
            }

            else{ // there exist a el whose place can be occupied by nums[i], so that we have the possibility to get a better seq

                *it = nums[i];

            }

        }

        return bs.size();
}

