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

void solve() {
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);

    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1,false);
    vector<ll> parent(n+1,-1);

    queue<ll> q;

    q.push(1);
    vis[1] = 1;

    while(!q.empty()){
        ll node = q.front();
        q.pop();

        if(node == n){

            break;
        }

        for(ll nei: adj[node]){
            
            if(vis[nei]) continue;

            parent[nei] = node;
            vis[nei] = 1;
            q.push(nei);
        }
    }

    if(!vis[n]){
        cout<<"IMPOSSIBLE";
        return;
    }

    ll curr = n;
    vector<ll> ans;

    while(curr != 1){
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(1);

    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<endl;

    for(int i=0;i< ans.size();i++){
        cout<< ans[i]<<" ";
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