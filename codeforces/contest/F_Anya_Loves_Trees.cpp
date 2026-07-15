#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int mn,mx,sz,ok;
};

vector<vector<int>> g;
vector<int> a;

Node dfs(int u) {
    if (g[u].empty()) return {a[u], a[u], 1, 1};
    
    int mn = 1e9, mx = -1e9,sz = 0,ok = 1;
    vector<int> b;
    
    for (int v : g[u]) {
        Node r = dfs(v);
        ok &= r.ok;

        mn=min(mn, r.mn);
        mx=max(mx, r.mx);

        sz +=r.sz;

        b.push_back(r.mn);
    }
    
    if (mx-mn != sz-1){
        ok=0;
    }
    
    int d = 0;
    int k = b.size();
    if (k > 1) {
        for (int i =0;i<k;i++) {
            if (b[i] > b[(i + 1)%k]) d++;
        }
        if (d>1) ok = 0;
    }
    
    return {mn, mx, sz, ok};
}

void solve() {
    int n;
    cin >> n;
    
    g.assign(n + 1,vector<int>());
    a.assign(n + 1,0);
    
    for (int i=2; i<=n;i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    
    for (int i=1; i<= n;i++) {
        cin >> a[i];
    }
    
    cout << (dfs(1).ok ?"YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}