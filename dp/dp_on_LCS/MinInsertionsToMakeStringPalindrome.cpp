#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n;

    int dp[501][501];

    int helper(int i, int j, string &s){
        if(i>j){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];


        if(s[i] == s[j]){//chars match to need for insertion
            return dp[i][j] = helper(i+1,j-1,s);
        }
        
        /*
        if the characters at i j don't match then i can have two cases:
        
        case 1: I can insert char at s[i] at jth position to make it equal, and move i+1, this will cost 1.

        case 2: I can insert char at s[j] at ith position to make it equal, and move j-1, this will cost 1.

        take the minimum operations returned by both cases 
        */
        return dp[i][j] = 1+min(helper(i,j-1,s), helper(i+1,j,s));
    }
    int minInsertions(string s) {
        n = s.size();

        memset(dp,-1, sizeof(dp));
        return helper(0,n-1,s);
    }
};