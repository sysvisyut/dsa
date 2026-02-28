#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    //sorting solution: O(n logn)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        vector<pair<int, vector<int>>> dis;

        for(auto it: points){
            double val = (it[0]*it[0])+(it[1]*it[1]);
            dis.push_back({val,it});
        }

        sort(dis.begin(),dis.end());

        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(dis[i].second);
        }

        return ans;
    }
};

// heap logic: O(n logk)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,vector<int>>> pq; // maxheap

        for(auto it: points){
            int dis = it[0]*it[0] + it[1]*it[1];
            pq.push({dis,it});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

};