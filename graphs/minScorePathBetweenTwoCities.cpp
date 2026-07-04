#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto e: roads){
            adj[e[0]].push_back({e[2],e[1]});
            adj[e[1]].push_back({e[2],e[0]});
        }

        vector<int> vis(n+1,0);
        
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &[w,v] : adj[node]){
                ans = min(ans,w);

                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;        
    }
};