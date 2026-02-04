#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


/*LOGIC: The number of edges needed to connect all the components is: (no of components-1)
we use DSU to find the extra edges in the graph if the extra edges is >= needed(👆🏻) then return n-1 or return -1*/

class DisJointSet{
    public:
    vector<int> parent,size;
    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extras = 0;
        
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) == ds.findUpar(v)){
                extras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int components =0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                components++;
            }
        }
        int ans = components-1; //min edges required to connect all components.

        if(extras >= ans) return ans;

        return -1;
    }

};