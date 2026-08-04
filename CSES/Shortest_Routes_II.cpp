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

const long long inf = 1e18;

void solve() {
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> adj(n+1,vector<long long>(n+1,inf));

    for(int i=1;i<=n;i++){
        adj[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u][v] = min(adj[u][v],w);
        adj[v][u] = min(adj[v][u],w);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(adj[i][k] != inf && adj[k][j] != inf){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int s,d;
        cin>>s>>d;

        if(adj[s][d] == inf){
            cout<<-1<<endl;
        }
        else{
            cout<<adj[s][d]<<endl;
        }
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