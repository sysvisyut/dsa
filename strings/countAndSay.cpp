#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    
    string helper(string num){

        string ans = "";

        int i =0;
        int n = num.size();

        while(i < n){
            int cnt = 1;
            while(i+1 < n && num[i] == num[i+1]){
                cnt++;
                i++;
            }

            ans+= to_string(cnt);
            ans+=(num[i]);
            i++;
        
        }

        return ans;
    }
    string countAndSay(int n) {
        
        vector<string> dp(n+1);
        dp[0] = "1";


        for(int i=1;i<n;i++){
            dp[i] = helper(dp[i-1]);
        } 

        return dp[n-1];
    }
};