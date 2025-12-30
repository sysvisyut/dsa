#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:

    bool bfs(int node, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }

                else if(color[it] == color[node]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i] == -1){
                if(bfs(i,color,graph) == false){
                    return false;
                }
            }
        }
        return true;
    }
};