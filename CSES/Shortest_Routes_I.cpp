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
#include <climits>
#include <numeric>
#include <iomanip>

using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({w,v});
    }

    vector<ll> dis(n+1,LLONG_MAX);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    pq.push({0,1});
    dis[1] = 0;
    
    while(!pq.empty()){
        ll node = pq.top().second;
        ll w = pq.top().first;

        pq.pop();

        if(w > dis[node]) continue;

        for(auto it: adj[node]){
            ll nei= it.second;
            ll edgWt = it.first;

            if(w+edgWt < dis[nei]){
                dis[nei] = w+edgWt;
                pq.push({dis[nei], nei});
            }
            
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
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