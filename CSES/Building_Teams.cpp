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

bool ok = true;

void dfs(int node, bool c, vector<vector<int>>& adj, vector<int>& col){

    if(c){
        col[node] = 1;
    }
    else{
        col[node] = 2;
    }

    int curr = col[node];

    for(int nei: adj[node]){
        if(col[nei] == -1){
            dfs(nei,!c,adj,col);
        }
        else{
            if(col[nei] == curr){
                ok = false;
                return;
            }
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj (n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> col(n+1,-1);
    bool red = true;

    for(int i=1;i<=n;i++){
        if(col[i]== -1){ //unvisited
            dfs(i,red,adj,col);
        }
        if(!ok){
            cout<<"IMPOSSIBLE";
            return;
        }   
    }

    // if(!ok){
    //     cout<<"IMPOSSIBLE";
    //     return;

    for(int i=1;i<=n;i++){
        cout<<col[i]<<" ";
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