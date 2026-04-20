#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int helper(int i,string& w,int x1,int y1, int x2,int y2,int dp[][7][7][7][7]){
        if(i >= w.size()){
            return 0;
        }
        int ans = dp[i][x1+1][y1+1][x2+1][y2+1];
        if(dp[i][x1+1][y1+1][x2+1][y2+1] != -1) return dp[i][x1+1][y1+1][x2+1][y2+1];
        int wx = (w[i]-'A')/6;
        int wy = (w[i]-'A')%6;

        if(x1== -1 && y1== -1 && x2 == -1 && y2 == -1){
            return dp[i][x1+1][y1+1][x2+1][y2+1]= 0+helper(i+1,w,wx,wy,x2,y2,dp);
        }
        else if(x1 == -1 && y1 == -1 ){
            return dp[i][x1+1][y1+1][x2+1][y2+1]= min(0+helper(i+1,w,wx,wy,x2,y2,dp), abs(wx-x2)+abs(wy-y2)+helper(i+1,w,x1,y1,wx,wy,dp));
        }
        else if(x2 == -1 && y2 == -1){
            return dp[i][x1+1][y1+1][x2+1][y2+1] = min(0+helper(i+1,w,x1,y1,wx,wy,dp), abs(wx-x1)+abs(wy-y1)+helper(i+1,w,wx,wy,x2,y2,dp));
        }
        return dp[i][x1+1][y1+1][x2+1][y2+1] = min(abs(wx-x2)+abs(wy-y2)+helper(i+1,w,x1,y1,wx,wy,dp),abs(wx-x1)+abs(wy-y1)+helper(i+1,w,wx,wy,x2,y2,dp));

}


    int minimumDistance(string word) {
         int dp[word.size()+1][7][7][7][7];
        memset(dp,-1,sizeof(dp));
        return helper(0,word,-1,-1,-1,-1,dp);
    }
};