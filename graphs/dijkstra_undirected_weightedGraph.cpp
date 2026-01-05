#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dis(V,1e9);
        
        dis[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int disTillNow = pq.top().first;
            pq.pop();
            
            if(disTillNow > dis[node]) continue; //remove outdated distances
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(disTillNow+edgeWt < dis[adjNode]){
                    dis[adjNode] = disTillNow+edgeWt;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};