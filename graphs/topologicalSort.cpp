/* toplogical sort exists only in directed-acyclic graphs(DAG), defined as if a set 
of edges given eg: 0->1 then in a topological sort order 0 always appears before 1 in
the valid sequence*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
  
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj, stack<int>& st){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges){
        // code here
        vector<vector<int>> adj(V);
        stack<int> st;
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};