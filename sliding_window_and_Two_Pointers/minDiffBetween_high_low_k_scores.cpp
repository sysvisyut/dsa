#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int global_mini = INT_MAX;

        for(int i=0;i<=n-k;i++){
            int mini =nums[i];
            int maxi =nums[i+k-1];//remember to check the index of bounds by taking example of the last valid i and seeing if that falls under the bound
            global_mini = min(maxi-mini, global_mini);
        }

        return global_mini;
    }
};