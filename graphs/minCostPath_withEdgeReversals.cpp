#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n,INT_MAX);
        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == n-1){
                return dist[n-1];
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int nodeDis = it.second;
                
                if(dis+nodeDis < dist[adjNode]){
                    dist[adjNode] = dis+nodeDis;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        return -1;
    }
};

