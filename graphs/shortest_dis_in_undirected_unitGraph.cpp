#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:

    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> dis(V,999);
        dis[src] = 0;
        queue<pair<int,int>> q;
        
        q.push({src,0});
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(dist+1 < dis[it]){
                    dis[it] = dist+1;
                    q.push({it,dist+1});
                }
                
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i] == 999){
                dis[i] = -1;
            }
        }
        
        return dis;
        
    }
};
