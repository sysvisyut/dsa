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

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

/*There should be atleast one route connecting any two cities,
we will use DSU to find connected components and the answer will be (number of connected components-1)*/

class DSU{
public:

    vector<int> parent;
    vector<int>rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }


    void unionByrank(int u, int v){
        int ult_u = findUnionParent(u);
        int ult_v = findUnionParent(v);

        if(ult_u == ult_v) return;

        if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else{
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }

    int findUnionParent(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findUnionParent(parent[u]);
    }
};

void solve() {
    
    int n,m;
    cin>>n>>m;

    DSU dsu(n+1);

    vector<vector<int>> g(n,vector<int>(2));

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        dsu.unionByrank(u,v);
    }

    vector<int> connected_components;

    for(int i=1;i<=n;i++){
        if(dsu.findUnionParent(i) == i){
            connected_components.push_back(i);
        }
    }

    int k = connected_components.size();

    cout<<k-1<<endl;

    for(int i=0;i<k-1;i++){
        cout<<connected_components[i]<<" "<<connected_components[i+1];
        cout<<endl;
    }

    
}

int main() {
    fastio;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}