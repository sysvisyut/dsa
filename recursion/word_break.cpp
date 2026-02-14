#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    bool solve(int idx, string& s,vector<int>& dp){
        if(idx >= s.size()){
            return dp[idx] = true;
        }
        if(st.find(s)!= st.end()) return true; //word is directly present in the dict
        if(dp[idx] != -1) return dp[idx];
        for(int l=1;l<=s.size();l++){
            string temp = s.substr(idx,l);

            if(st.count(temp) && solve(idx+l, s,dp) ){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict){
            st.insert(it);
        }
        vector<int> dp(301,-1);
        return solve(0,s,dp);
    }
};