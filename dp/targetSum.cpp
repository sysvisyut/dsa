#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            The problem is group +ve and group -ve whose sum is target
            so eq is 
                P-N = target---> eq1
            
            also P+N = total---> eq2

            add eq1 and eq2 
            we get 
                2P = target+total
                -> P  target+total/2 ---> new target

            finally the problem can the changed as total ways to make new target using nums
        
        */

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);

        if((target+sum)&1 || abs(target) > sum) return 0;

        int nt = (target+sum)/2;

        vector<int> dp(nt+1,0);
        // dp[s] represents number of ways to form sum s
        
        dp[0] = 1; // sum 0 can be always formed by not taking any element

        for(int num: nums){
            for(int j = nt;j>=num;j--){
                dp[j]+= dp[j-num];
            }
        }

        return dp[nt];
    }
};