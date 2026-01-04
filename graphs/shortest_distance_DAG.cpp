#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
  
    void topoSrt(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis,stack<int> &st){
        vis[node] =1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSrt(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            adj[u].push_back({v,wt});
        }
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSrt(i,adj,vis,st);  //stack ready with toposort
            }
        }
        
        vector<int> dis(V,INT_MAX);
        dis[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){       // relax the edges as per the order of toposort
                int v = it.first;
                int wt = it.second;
                if(dis[node]!= INT_MAX && dis[node]+wt < dis[v]){
                    dis[v] = dis[node]+wt;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }
        
        return dis;
        
    }
};
