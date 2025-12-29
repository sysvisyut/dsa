#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
  
    bool detect(int src,vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        
        for(auto &e: edges){
            int u = e[0];       //create adjacency list from edges
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)){
                     return true;
                }
            }
        }
        return false;
    }
};