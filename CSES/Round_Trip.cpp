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

vector<int> parent,vis;
vector<vector<int>> adj;
int startNode = -1;
int endNode = -1;


bool dfs(int node, int p){

    vis[node] =1;
    
    for(int nei: adj[node]){
        if(nei == p){
            continue;
        }
        if(!vis[nei]){
            parent[nei] = node;
            if(dfs(nei,node)){
                return true;
            }
        }
        else{
            startNode = nei;
            endNode = node;
            return true;
        }
    }

    return false;

}

void solve() {
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = false;

    vis.resize(n+1,0);
    parent.resize(n+1,-1);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                ok = true;
                break;
            }
        }
    }

    if(!ok){
        cout<<"IMPOSSIBLE";
        return;
    }

    vector<int> cycle;
    int curr = endNode;
    cycle.push_back(startNode);
    
    while(curr!= startNode){
        cycle.push_back(curr);
        curr = parent[curr];
    }

    cycle.push_back(startNode);
    reverse(cycle.begin(), cycle.end());
    cout<<cycle.size()<<endl;

    for(int i=0;i<cycle.size();i++){
        cout<<cycle[i]<<" ";
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