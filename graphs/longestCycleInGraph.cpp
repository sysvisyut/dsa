#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n;
    int res = -1;

    void dfs(int u,vector<int>& edges, vector<int>& vis, vector<int>& path,vector<int>& cnt){
        if(u != -1){
            vis[u] = 1;
            path[u] = 1;

            int v = edges[u];
            
            if(v!= -1 && !vis[v]){

                cnt[v] = cnt[u]+1;

                dfs(v,edges,vis,path,cnt);
            }
            else if(v != -1 && path[v] == 1){
                res = max(res,cnt[u]-cnt[v]+1);
            }
            path[u] = 0;
        }
    }
    int longestCycle(vector<int>& edges){

        n = edges.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> cnt(n,1);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,path,cnt);
            }
        }


        return res;
    }
};