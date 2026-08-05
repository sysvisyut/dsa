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

    void dfs(int node, vector<bool>& vis, vector<vector<int>>& rooms){
        vis[node] = true;

        for(int nei: rooms[node]){
            if(!vis[nei]){
                dfs(nei,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        
        vector<bool> vis(n,false);

        dfs(0,vis,rooms);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }
};