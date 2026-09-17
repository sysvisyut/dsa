#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = 0;

        int sum = 0;
        vector<int> minBefore(n,INT_MAX);
        int mini = INT_MAX;

        int res = INT_MAX;

        while(r < n){
            sum+=nums[r];

            while(sum > target){
                sum-=nums[l];
                l++;
            }
            if(sum == target){
                int len = r-l+1;

                if(l > 0 && minBefore[l-1] != INT_MAX){
                    res = min(res,len+minBefore[l-1]);
                }
                mini = min(mini,len);
            }

            minBefore[r] = mini;
            r++;
        }

        return res== INT_MAX ? -1 :res;

    }
};