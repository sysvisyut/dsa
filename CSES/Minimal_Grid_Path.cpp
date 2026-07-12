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

int dx[] = {0,1};
int dy[] = {1,0};
int n;

string res;

void solve() {
    cin>> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(n,false));
    res ="";
    res+=grid[0][0];

    vector<pair<int,int>> currLayer;
    currLayer.push_back({0,0});
    
    vis[0][0] = true;

    while(res.size() < 2*n -1){
        char best = 'Z'+1;
        vector<pair<int,int>> nextLayer;
         for(auto[ux, uy]: currLayer){
            for(int i=0;i<2;i++){
                int vx = ux+dx[i];
                int vy = uy+dy[i];

                if(vx>=n || vy>=n || vis[vx][vy] ){
                    continue;
                }

                vis[vx][vy] = 1;
                nextLayer.push_back({vx,vy});

                if(grid[vx][vy] < best){
                    best = grid[vx][vy];
                }
            }
        }

        res+=best;

        vector<pair<int,int>> filteredNextLayer;

        for(auto[ux,uy] : nextLayer){
            if(grid[ux][uy] == best){
                filteredNextLayer.push_back({ux,uy});
            }
        }

        currLayer = move(filteredNextLayer);
    }

}

int main() {
    fastio;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    cout<< res;

    return 0;
}