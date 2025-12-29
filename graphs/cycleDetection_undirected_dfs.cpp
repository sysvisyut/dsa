#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    bool detect(int node,int parent, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(detect(it,node,vis,adj))
                    return true;    // recursion calls that are before the actual call that had cycle so if that call gave me a true i return true so indicate, below me i found someone who returned true;
            }
            else if(it != parent){
                return true;        // return true for real cycle
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,vis,adj)) return true;
            }
        }
        
        return false;
        
    }
};