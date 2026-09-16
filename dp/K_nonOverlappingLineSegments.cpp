#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
typedef long long ll;
    const ll mod = 1e9+7;

    ll dp[1005][1005][2];

    int helper(int i,bool start,int n, int k){
        if(k == 0) return 1;

        if(i == n){
            return 0;
        }

        if(dp[i][k][start] != -1) return dp[i][k][start];
        ll ans = 0;

        if(start){
            ans = (ans+ helper(i,false,n,k-1))%mod;
            ans = (ans+ helper(i+1,true,n,k))%mod;
        }
        else{
            ans = (ans + helper(i+1,true, n, k))%mod;
            ans = (ans+ helper(i+1,false,n,k))%mod;
        }

        return dp[i][k][start] = ans;

    }
    int numberOfSets(int n, int k) {

        memset(dp,-1,sizeof(dp));
        return helper(0,false,n,k);

    }
};