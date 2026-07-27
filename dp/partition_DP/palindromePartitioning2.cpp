#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int t[2001][2001];
    int minCut(string s) {
        
        int n = s.size();
        
        memset(t,0, sizeof(t));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;

                if(i == j){
                    t[i][j] = 1;
                }
                else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                }

                else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n+1,0);

        for(int i=0;i<n;i++){
            if(t[0][i]){
                dp[i] = 0;
            }

            else{
                dp[i] = INT_MAX;

                for(int k=0;k<i;k++){
                    if(t[k+1][i] == 1 && 1+dp[k] < dp[i]){
                        dp[i] =  1+dp[k];
                    }
                }
            }
        }

        return dp[n-1];
    }
};