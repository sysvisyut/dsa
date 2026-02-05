#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class DisJointSet{
    public:
    vector<int> parent;
    vector<int> size;

    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(parent[node] == node) return node;

        return parent[node]= findUpar(parent[node]);
    }

    void unionBySize(int u,int v){
        int ulp_u= findUpar(u);
        int ulp_v= findUpar(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v]; 
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mapMailNode;
        DisJointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j= 1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size() ==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};