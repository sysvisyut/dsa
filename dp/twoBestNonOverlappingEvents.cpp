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
    
    int dp[100001][3];

    int binarySearch(vector<vector<int>>& events, int et){

        int l = 0;
        int r = events.size()-1;
        int res = n+1;

        while(l <= r){
            int mid = l+(r-l)/2;

            if(events[mid][0] > et){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
    
    int helper(int i, int cnt, vector<vector<int>>& events){
        if(cnt == 2 || i >=n){
            return 0;
        }

        if(dp[i][cnt] != -1) return dp[i][cnt];

        int nextValidIdx = binarySearch(events, events[i][1]);

        int take = events[i][2]+helper(nextValidIdx, cnt+1,events);
        int skip = helper(i+1,cnt,events);

        return dp[i][cnt] = max(take,skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        
        n = events.size();
        memset(dp,-1,sizeof(dp));
        sort(events.begin(), events.end());

        int cnt = 0;
        return helper(0,cnt,events);
    }
};