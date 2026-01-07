#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dis(n,1e18),ways(n,0);
        dis[0]=0;
        ways[0]=1;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        pq.push({0,0});
        int mod = 1e9+7;
        while(!pq.empty()){
            long long wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (wt > dis[node]) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                long long nodeWt = it.second;
                //this is the first time we find this shorter path
                if(wt+nodeWt < dis[adjNode]){
                    dis[adjNode] = wt+nodeWt;
                    pq.push({dis[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                //someone else came to the last node with the same shortest distance
                else if(wt+nodeWt == dis[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;

    }
};