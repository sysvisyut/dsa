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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y,vector<vector<char>>&g, vector<vector<bool>>& vis, int n, int m){
    vis[x][y] = 1;

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && nx < n && ny>=0 && ny<m && !vis[nx][ny] && g[nx][ny] == '.'){
            dfs(nx,ny,g,vis,n,m);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> g(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    int rooms = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && g[i][j] == '.'){
                rooms++;
                dfs(i,j,g,vis,n,m);
            }
        }
    }

    cout<<rooms<<endl;

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