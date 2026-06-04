#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int r =0;

        int curr =0;
        int ans = INT_MAX;

        while(r < n){
            curr+=nums[r];

            while(curr >= target){
                ans = min(ans,r-l+1);
                curr-=nums[l];
                l++;
            }
            r++;
        }

        return ans==INT_MAX ?0 :ans;
    }
};