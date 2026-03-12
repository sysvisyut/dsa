#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    class DisJointSet{
        vector<int> size,parent;

        public:
            DisJointSet(int n){
                size.resize(n+1,0);
                parent.resize(n+1);

                for(int i=0;i<n;i++){
                    parent[i] = i;
                }
            }

            int findUparent(int node){
                if(node == parent[node]) return node;

                return parent[node] = findUparent(parent[node]);
            }

            void unionSize(int u,int v){
                int ultParent_u = findUparent(u);
                int ultParent_v = findUparent(v);

                if(ultParent_u == ultParent_v){
                    return;
                }
                if(size[ultParent_u] < size[ultParent_v]){
                    parent[ultParent_u] = ultParent_v;
                    size[ultParent_v]+= size[ultParent_u];
                }
                else{
                    parent[ultParent_v] = ultParent_u;
                    size[ultParent_u]+= size[ultParent_v];
                }
            }
    };

    bool check(int n,vector<vector<int>>& edges, int k, int mid){
        DisJointSet ds(n);

        vector<vector<int>> upgradeCandidates;
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int m = it[3];
            if(m==1){
                    if(s < mid){
                        return false;
                    }
                    ds.unionSize(u,v);
                }else{
                    if(s>= mid){
                        ds.unionSize(u,v);

                    }
                    else if(2*s >= mid){
                        upgradeCandidates.push_back({u,v});
                }
            }
        }
        
        for(auto& edge: upgradeCandidates){
            int u = edge[0];int v = edge[1];
            if(ds.findUparent(u) != ds.findUparent(v)){
                if(k<=0){
                    continue;
                }
                ds.unionSize(u,v);
                k--;
            }
        }

        int root = ds.findUparent(0);

        for(int i=1;i<n;i++){
            if(ds.findUparent(i) != root)return false;
        }

        return true;

    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l = 1;
        int r = 2*(1e5);
        DisJointSet ds(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int m = it[3];


            if(m==1){
                if(ds.findUparent(u) == ds.findUparent(v)){
                    return -1;
                }
                ds.unionSize(u,v);
            }
        }
        int res = -1;

        while(l <= r){
            int mid = l+(r-l)/2;


            if(check(n,edges,k,mid)){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }


        return res;

    }
};