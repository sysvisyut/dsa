#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        //{stops,{node,dis}}
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dist+wt < dis[adjNode] && stops <= k){ // stops always 1 greater than the actual 1->2->3 from 1 to 3 here 2 stops considered but actually its 1 stop.
                    dis[adjNode] = dist+wt;
                    q.push({stops+1,{adjNode, dis[adjNode]}});
                }
            }
        }

        if(dis[dst] == 1e9) return -1;

        return dis[dst];
    }
};