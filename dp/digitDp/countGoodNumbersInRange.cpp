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
    ll dp[20][2][11];
    string num;

    long long helper(int idx, int tight, int prev, int k){
        if(idx == num.size()){
            return 1;
        }
        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];
        
        ll ans = 0;

        int limit = (tight ? num[idx]-'0' :9);

        for(int d=0;d<= limit;d++){
            int nprev, ntight;

            if(prev != 10 && abs(d-prev) >k) continue;
            
            if(prev == 10 && d==0){
                nprev = 10;
            }
            else{
                nprev = d;
            }
            ntight = (tight && d ==limit);
            
            ans+=helper(idx+1,ntight,nprev,k);
        }
        return dp[idx][tight][prev] = ans;
    }

    long long solve(long long x, int k){
        if(x < 0) return 0;

        num = to_string(x);
        memset(dp,-1, sizeof(dp));

        return helper(0,1,10,k);
    }
    long long goodIntegers(long long l, long long r, int k) {
        return solve(r,k)-solve(l-1,k);
        
    }
};