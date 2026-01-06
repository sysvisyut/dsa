#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> dis(r,vector<int>(c,1e9));
        dis[0][0] = 0;

        priority_queue<pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,+1,0,-1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;


            pq.pop();
            
            if (diff > dis[row][col]) continue;
            if(row == r-1 && col == c-1) return diff;

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow >=0 && nrow <r && ncol >=0 && ncol <c){
                    int newEffort = max(abs(heights[row][col]-heights[nrow][ncol]),diff);

                    if(newEffort < dis[nrow][ncol]){
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};