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

char dir[4] ={'U','R','D','L'};


void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> g(n,vector<char>(m));

    pair<int,int> start, end;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j] == 'A'){
                start= {i,j};
            }
            else if(g[i][j] == 'B'){
                end = {i,j};
            }
        }
    }


    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveTaken(n, vector<char>(m));


    q.push(start);
    vis[start.first][start.second] = 1;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        

        if(x == end.first && y == end.second){
            break;
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            
            if(nx>=0 && nx<n && ny>=0 && ny < m && !vis[nx][ny] && g[nx][ny] != '#'){
                parent[nx][ny] = {x,y};
                moveTaken[nx][ny] = dir[i];
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

    if(!vis[end.first][end.second]){

        cout<<"NO"<<endl;
        return;
    }

    string path;

    pair<int, int> curr = end;

    while(curr != start){
        path+= moveTaken[curr.first][curr.second];
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
    return;
 
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