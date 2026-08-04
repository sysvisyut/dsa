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

const ll inf = -1e18;

void solve() {
    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<ll,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;

        adj[u].push_back({w,v});
        adj[v].push_back({w,u});

    }
    vector<ll> dis(n+1,inf);

    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    pq.push({0,1});
    dis[1] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        ll w = pq.top().first;

        if(w < dis[node]) continue;

        for(auto it: adj[node]){
            int nei = it.second;
            ll edgWt = it.first;

            if(w+edgWt > dis[nei]){
                dis[nei] = w+edgWt;
                pq.push({dis[nei],nei});
            }
        }
    }
    if(dis[n] == inf){
        cout<< -1<<endl;
    }
    else{
        cout<<dis[n]<<endl;
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