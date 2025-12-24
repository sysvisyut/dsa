#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i=0;i<n;i++){              //conversion of adjacency matrix to adjacency list.
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j ){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;      
                dfs(i,adj,vis); //this call is made for cnt times
                // in each dfs call all the nodes in a single province is marked as visited
            }
        }
        return cnt;
    }
};