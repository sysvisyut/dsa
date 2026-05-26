#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:

    int dfs(int node, vector<long long>& dis, int n,vector<vector<pair<int,int>>>& adj,vector<int>& dp){
        int mod = 1e9+7;
        if(dp[node] != -1) return dp[node]; //already this node was explored before and valid ans stored in dp[node]
        if(node == n) return 1;

    

        long long ans = 0;

        for(auto it: adj[node]){
            int nei = it.second;
            if(dis[node] > dis[nei]){
                ans= (ans+ dfs(nei,dis,n,adj,dp))%mod;
            }
        }

        return dp[node] = ans;


    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        /*
        First use dijikstra to find the shortest path to end node from all the other node,
        i.e get the dis array.
        
        use this dis array on dfs to find the no of restricted paths
        
        restricted path should have all the final shortest paths in decreasing order
        in tc 1: 1->2->3->5, compare it with their dis array values we get
        4 > 2 > 1 > 0*/

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto e: edges){
            int u = e[0];
            int v =e[1];
            int wt = e[2];

            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }

        vector<long long> dis(n+1,LLONG_MAX);
        dis[n] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0,n});

        while(!pq.empty()){
            int node = pq.top().second;
            long long wtTillNow = pq.top().first;

            pq.pop();

            if(wtTillNow > dis[node]) continue;

            for(auto it: adj[node]){
                int adjNode = it.second;
                int adjWt = it.first;

                if(adjWt+wtTillNow < dis[adjNode]){
                    dis[adjNode] = adjWt+wtTillNow;
                    pq.push({dis[adjNode],adjNode});
                }
            } 
        }

        vector<int> dp(n+1,-1);


        return dfs(1,dis,n,adj,dp);     

        


    }
};