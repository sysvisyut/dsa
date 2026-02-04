#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class DisJointSet{
    vector<int> rank, parent, size;

    public:
        DisJointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findUparent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUparent(parent[node]); //path compression.
        }
        void unionRank(int u,int v){
            int ultParent_u = findUparent(u);
            int uldParent_v = findUparent(v);

            if(ultParent_u == uldParent_v){
                return;
            }
            if(rank[ultParent_u] < rank[uldParent_v]){
                parent[ultParent_u] = uldParent_v;
            }
            else if(rank[uldParent_v] < rank[ultParent_u]){
                parent[uldParent_v] = ultParent_u;
            }
            else{
                parent[uldParent_v] = ultParent_u;
                rank[ultParent_u]++;
            }
        }
};

int main(){
    DisJointSet ds(7);
    ds.unionRank(1,2);
    ds.unionRank(2,3);
    ds.unionRank(4,5);
    ds.unionRank(6,7);
    ds.unionRank(5,6);

    if(ds.findUparent(3) == ds.findUparent(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }

    ds.unionRank(3,7);
     if(ds.findUparent(3) == ds.findUparent(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Not Same\n";
    }
    return 0;
}