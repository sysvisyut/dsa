#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:

    void dfs(int node,vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;

        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei,adj,vis);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& g) {
        
        vector<vector<int>> adj(n);

        for(auto it: g){
            int u= it[0];
            int v= it[1];

            adj[u].push_back(v);
        }


        vector<bool> vis(n,false);
        
        dfs(k,adj,vis);

        for(auto it: g){
            int u = it[0];
            int v = it[1];

            if(vis[u]){
                continue;
            }
            if(vis[v]){
                vector<int> ans;

                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }

                return ans;

            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }

        return ans;

    }
};