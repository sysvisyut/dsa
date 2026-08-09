#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:

    int findParent(int node, vector<int>& parent){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node],parent); //path compression
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<int> parent(n+1);

        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }

        for(auto &e: edges){
            
            int p1 = findParent(e[0],parent);
            int p2 = findParent(e[1],parent);

            if(p1 == p2){ //parent's are same connecting this node will form cycle 
                return e;
            }
            parent[p1] = p2; //store parent as this node
        }

        return {-1,-1};
    }
};