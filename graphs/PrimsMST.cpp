#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int dis = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back({v,dis});
            adj[v].push_back({u,dis});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        
        int sum =0;
        vector<int> vis(V,0);
        //just the sum of the mst is asked so no need of parent.
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(vis[node] == 1){
                continue;   //node cant be part of MST.
            }
            vis[node] =1;
            sum+= wt;
            for(auto e: adj[node]){
                int adjNode = e.first;
                int nodeWt = e.second;
                if(!vis[adjNode]){
                    pq.push({nodeWt,adjNode});
                }
            }
        }
        return sum;
    }
};