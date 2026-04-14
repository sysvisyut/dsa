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
    ll helper(int i,int j,vector<int>& robot,vector<ll>& fac,vector<vector<ll>>& dp){
        if(i == robot.size()){
            return 0;
        }
        if(j >= fac.size()) return 1e12;

        if(dp[i][j] != -1) return dp[i][j];

        ll use = abs(robot[i]-fac[j])+helper(i+1,j+1,robot,fac,dp);
        ll skip = helper(i,j+1,robot,fac,dp);

        return dp[i][j] = min(use,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ll m = robot.size();
        int size = factory.size();
        sort(robot.begin(),robot.end());

        vector<ll> fac;
        
        for(int i=0;i<size;i++){
            int pos = factory[i][0];
            int freq = factory[i][1];
            for(int j=0;j<freq;j++){
                fac.push_back(pos);
            }
        }

        sort(fac.begin(),fac.end());
        ll n = fac.size();
        vector<vector<ll>> dp(m,vector<ll>(n,-1));

        return helper(0,0,robot,fac,dp);
    }
};