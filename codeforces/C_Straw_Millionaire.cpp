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


int main() {
  

    int n, m;
    cin>>n>>m;

    
    vector<vector<int>> adj(n+ 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    vector<bool> vis(n+ 1, false);
    queue<int> q;

   
    q.push(1);
    vis[1] = true;
    int cnt = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;

        
        for (int e : adj[curr]) {
            if (!vis[e]) {
                vis[e] = true;
                q.push(e);
            }
        }
    }


    cout << cnt << endl;

    return 0;
}