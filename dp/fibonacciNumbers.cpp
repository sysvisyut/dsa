#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int fib(int n) {
        //if(n==0) return 0;
        // vector<int> dp(n+1,0);
        // dp[1] = 1;

        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        //space optimized:
        
        if(n <= 1) return n;
        int prev1 = 1;
        int prev2 = 0;

        for(int i=2;i<=n;i++){
            int curr = prev1+prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};