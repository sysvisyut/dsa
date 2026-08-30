#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int i = 0;
        int j = n-1;

        while(i< j){
            curr_sum = nums[i]+nums[j];
            i++;
            j--;
            max_sum = max(curr_sum,max_sum);
        }

        return max_sum;

    }
};