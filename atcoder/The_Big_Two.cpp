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

using pii = pair<int, int>;

int n, m;
vector<pii> adj;
set<pii> ans;

bool isValid(int x, int y) {
    for (auto [u, v] : adj) {
        if (u != x && u != y && v != x && v != y)
            return false;
    }
    return true;
}

void helper(int node) {

    for (auto [u, v] : adj) {

        if(u==node || v == node)
            continue;

        if(isValid(node,u))
            ans.insert({min(node, u), max(node, u)});

        if(isValid(node,v))
            ans.insert({min(node, v), max(node, v)});

        return;
    }

    for (int p =1; p<=n; p++) {
        if (p ==node)
            continue;

        ans.insert({min(node,p), max(node,p)});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    adj.resize(m);

    for (int i=0; i<m;i++) {
        cin >> adj[i].first >> adj[i].second;
    }

    helper(adj[0].first);
    helper(adj[0].second);

    cout << ans.size();

    return 0;
}