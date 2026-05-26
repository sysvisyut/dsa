#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start_node, int end_node) {
        
        vector<vector<pair<double,int>>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = prob[i];

            adj[u].push_back({p,v});
            adj[v].push_back({p,u});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> dis(n,-1);
        pq.push({1.0,start_node});
        dis[start_node] = 1.0;

        while(!pq.empty()){
            int node = pq.top().second;
            double wtTillNow = pq.top().first;
            pq.pop();

            if(wtTillNow < dis[node]) continue;

            for(auto it: adj[node]){
                int nei = it.second;
                double edjWt =it.first;

                if(edjWt*wtTillNow > dis[nei]){
                    dis[nei] = edjWt*wtTillNow;
                    pq.push({dis[nei], nei});
                }
            }
        }
        double ans = 0;

        return (dis[end_node] == -1)? ans: dis[end_node];
    }
};