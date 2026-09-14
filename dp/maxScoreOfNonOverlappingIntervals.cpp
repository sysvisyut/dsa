#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    struct node{
        long long score = -1;
        vector<int> idxs;
    };

    int n;
    vector<int> nextIdx;

    vector<vector<node>> dp;

    node helper(int i, int k, vector<vector<int>>& intervals){

        if(k ==0 || i>=n){
            node res;
            res.score = 0;
            return res;
        }
        if(dp[i][k].score != -1){
            return dp[i][k];
        }

        node skip = helper(i+1,k,intervals);

        int j = nextIdx[i];
        int w = intervals[i][2];
        int idx = intervals[i][3];

        node temp = helper(j,k-1, intervals);

        node take;

        take.score = temp.score+w;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);
        sort(take.idxs.begin(), take.idxs.end());

        node res;

        if(skip.score > take.score){
            res = skip;
        }
        else if(skip.score < take.score){
            res = take;
        }
        else{
            res = (skip.idxs < take.idxs) ?skip: take;
        }

        return dp[i][k] = res;

    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        n = intervals.size();


        for(int i=0;i<n;i++){
            intervals[i].push_back(i); //store the og indexes 
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);
        for(int i=0;i<n;i++){
            int endTime = intervals[i][1];
            
            auto it = upper_bound(intervals.begin(), intervals.end(), endTime,
            [](int val,const vector<int>& nxt){
                return val < nxt[0];// finding intervals whose st time is greater than the curr interval's end time.
            }
            );

            int idx = it-intervals.begin();
            nextIdx[i] = idx;
        }
        int k = 4;

        dp.resize(n+1,vector<node>(k+1));
        return helper(0,k,intervals).idxs;
        
    }
};