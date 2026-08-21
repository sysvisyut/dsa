#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n,m;
    
    int dp[1001][1001];

    // int helper(int i, int j, string &s, string &t){
    //     if(i == n || j ==m){
    //         return 0;
    //     }

    //     if(dp[i][j] != - 1) return dp[i][j];

    //     if(s[i] == t[j]){
    //         return dp[i][j] = 1+helper(i+1,j+1,s,t);
    //     }
    //     else{
    //         return dp[i][j] = max(helper(i+1,j,s,t), helper(i,j+1,s,t));
    //     }
    // }
    int longestCommonSubsequence(string s, string t) {
        n = s.size();
        m = t.size();
        
        memset(dp,0, sizeof(dp));

        for(int i= n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];
        
    }
};