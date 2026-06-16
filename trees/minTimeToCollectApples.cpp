#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:

    int helper(int node,int par,unordered_map<int,vector<int>>& adj, vector<bool>& hasApple){
        int time = 0;

        for(int &child : adj[node]){
            if(child == par) continue;

            int timeFromChild = helper(child,node,adj,hasApple);
            //only add 2 if the child itself has apples or some node under child has return time > 0 so we need travel throught that path and comeback again so +2
            if(timeFromChild>0 || hasApple[child]){
                time+= timeFromChild+2;
            }
        }

        return time;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        /*apply dfs */

        unordered_map<int,vector<int>> adj;

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return helper(0, -1,adj, hasApple);


               
    }
};