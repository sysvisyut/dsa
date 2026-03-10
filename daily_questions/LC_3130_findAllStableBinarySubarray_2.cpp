#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero+1,vector<vector<int>>(one+1,vector<int>(2,0)));

        for(int i=0;i<=min(zero,limit);i++){
            dp[i][0][0] = 1;
        }
        for(int j=0;j<=min(one,limit);j++){
            dp[0][j][1] = 1;
        }


        for(int i=0;i<= zero;i++){
            for(int j=0;j<= one;j++){

                if(i==0 || j==0) continue; //invalid dp cell

                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%mod; 
                if(j-1 >= limit){
                    dp[i][j][1] = (dp[i][j][1]- dp[i][j-1-limit][0]+mod)%mod;
                }
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])%mod; 
                if(i-1 >= limit){
                    dp[i][j][0] = (dp[i][j][0]- dp[i-1-limit][j][1]+mod)%mod;
                }
            }
        }


        return (dp[zero][one][0]+ dp[zero][one][1])%mod;
    }
};  