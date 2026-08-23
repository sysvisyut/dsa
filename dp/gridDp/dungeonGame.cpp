#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n, m;
    int dp[201][201];

    // int helper(int i,int j, vector<vector<int>>& g){
    //     if(i > n-1 || j > m-1){
    //         return 1e9;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(i == n-1 && j == m-1){
    //         if(g[i][j] > 0){
    //             return dp[i][j] = 1;
    //         }
    //         return dp[i][j] = abs(g[i][j])+1; //the end cell has -ve val, so
    //         the knight should have one more than abs(val) so that his health
    //         is 1.
    //     }

    //     int down = helper(i+1,j,g);
    //     int right = helper(i,j+1,g);

    //     int res = min(down, right) - g[i][j];

    //     return dp[i][j] = (res > 0)? res: 1;
    // }
    int calculateMinimumHP(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();

        memset(dp, 0, sizeof(dp));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    if (g[i][j] > 0) {
                        dp[i][j] = 1;
                    } else
                        dp[i][j] = abs(g[i][j]) + 1;
                } 
                else {
                    int down = (i + 1 >= n) ? 1e9 : dp[i + 1][j];
                    int right = (j + 1 >= m) ? 1e9 : dp[i][j + 1];

                    int res = min(down, right) - g[i][j];

                    dp[i][j] = (res > 0) ? res : 1;
                }
            }
        }
        return dp[0][0];
    }
};