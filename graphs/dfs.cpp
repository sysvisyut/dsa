#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public: 
    vector<int> ans;
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;        //recursively mark nodes as visited add them in the traversal and explore neighbours
                dfs(it,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
 
        int n = adj.size();
        vector<int> vis(n);
        int start = 0;
        vis[0] = 1;
        dfs(start,vis,adj);
        return ans;
    }
};