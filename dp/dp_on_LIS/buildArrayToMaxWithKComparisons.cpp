#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int N,M,K;
    int dp[51][51][101];
    const int mod = 1e9+7;

    int helper(int i, int searchCost, int maxTillNow){
        if(i == N){
            if(searchCost == K){
                return dp[i][searchCost][maxTillNow] = 1;
            }
            return dp[i][searchCost][maxTillNow] = 0;
        }

        if(dp[i][searchCost][maxTillNow] != -1) return dp[i][searchCost][maxTillNow];

        long long res = 0;
        for(int idx =1; idx<=M; idx++){
            if(idx > maxTillNow){
                res = (res+helper(i+1,searchCost+1, idx))%mod;
            }
            else{
                res= (res+helper(i+1,searchCost, maxTillNow))%mod;
            }
        }

        return dp[i][searchCost][maxTillNow] = res%mod;
    }
    int numOfArrays(int n, int m, int k) {
        
        N=n;M=m;K=k;

        memset(dp ,-1, sizeof(dp));
        return helper(0,0,0);
    }
};