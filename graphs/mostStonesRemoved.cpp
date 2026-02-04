#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


/*logic: In each of the connected components remove all elements except one
ans = number of stones- no of connected components*/

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow =0;
        int maxCol =0;

        for(auto it: stones){
            maxRow = max(maxRow,it[0]); //finds the max col where the stone is present
            maxCol = max(maxCol,it[1]); //finds the max row where the stone is present
        }
        DisJointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;  //ds to store the nodes

        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;   
            stoneNodes[nodeCol] = 1;    
        }

        int cnt = 0;

        for(auto it: stoneNodes){
            if(ds.findUpar(it.first) == it.first){
                cnt++;  //count the number of components
            }
        }
        return n-cnt;
    }
};