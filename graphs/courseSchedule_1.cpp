#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathVis,vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node]= 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(!dfs(it,vis,pathVis,adj)) return false;
            }
            else if(pathVis[it]){
                return false;
            }
        }
        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);

        vector<vector<int>> adj(numCourses); // creates [ [],[],[],[] ] if numcourses =4

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]); //directed graph
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj) == false) return false;
            }
        }
        return true;
    }
};