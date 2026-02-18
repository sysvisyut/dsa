#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool helper(int i, int j,string &s,vector<vector<int>>& dp){
        if(i>j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = helper(i+1,j-1,s,dp);
        }
        else return dp[i][j] = false;

    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int sp =0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(helper(i,j,s,dp)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};