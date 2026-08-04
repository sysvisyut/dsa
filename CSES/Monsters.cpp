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

using pii = pair<int,int>;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

vector<char> dir = {'U','D','R','L'};

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> g(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    vector<vector<int>> monster_time(n,vector<int>(m,INT_MAX));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<char>> parent(n,vector<char>(m));

    queue<pii> q;

    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
                q.push({i,j});
                monster_time[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]!='#'){
                if(monster_time[nx][ny]>monster_time[x][y]+1){
                    monster_time[nx][ny]=monster_time[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    pii start,end={-1,-1};

    queue<pii> q1;

    for(int i=0;i<n;i++){
        bool found=false;
        for(int j=0;j<m;j++){
            if(g[i][j]=='A'){
                start={i,j};
                q1.push(start);
                found=true;
                break;
            }
        }
        if(found) break;
    }

    vis.assign(n,vector<int>(m,0));
    vis[start.first][start.second]=1;

    vector<vector<int>> dis(n,vector<int>(m,0));

    bool escaped=false;

    // If already on boundary
    if(start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1){
        escaped=true;
        end=start;
    }

    while(!q1.empty() && !escaped){
        auto [x,y]=q1.front();
        q1.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m &&
               g[nx][ny]!='#' && !vis[nx][ny]){

                if(dis[x][y]+1 < monster_time[nx][ny]){
                    vis[nx][ny]=1;
                    dis[nx][ny]=dis[x][y]+1;
                    parent[nx][ny]=dir[i];
                    q1.push({nx,ny});

                    if(nx==0 || nx==n-1 || ny==0 || ny==m-1){
                        escaped=true;
                        end={nx,ny};
                        break;
                    }
                }
            }
        }
    }

    if(!escaped){
        cout<<"NO\n";
        return;
    }

    string path;
    pii curr=end;

    while(curr!=start){
        char d=parent[curr.first][curr.second];
        path.push_back(d);

        int idx=find(dir.begin(),dir.end(),d)-dir.begin();
        curr.first-=dx[idx];
        curr.second-=dy[idx];
    }

    reverse(path.begin(),path.end());

    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
}

int main() {
    fastio;

    solve();

    return 0;
}