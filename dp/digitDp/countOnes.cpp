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
    ll dp[20][2][20];

    long long helper(int idx, int tight, int cnt, string &s){

        if(idx == s.size()){
            return cnt;
        }

        if(dp[idx][tight][cnt] != -1){
            return dp[idx][tight][cnt];
        }

        int limit = (tight ? s[idx]-'0' : 9);
        ll ans = 0;

        for(int d=0; d<= limit; d++){
            int newTight = tight && (d == limit);

            ans+=helper(idx+1,newTight,cnt+(d==1),s);
        }

        return dp[idx][tight][cnt] = ans;
    }

    int countDigitOne(int n){

        memset(dp,-1,sizeof(dp));
        string num = to_string(n);

        return helper(0,1,0,num);
        
    }
};