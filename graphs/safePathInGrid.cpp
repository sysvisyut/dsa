#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int n,m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,-0,-1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        int h = health - grid[0][0];

        if(h <= 0) return false;

        vector<vector<int>> bestH(n,vector<int>(m,-1));

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, h});
        bestH[0][0] = h;

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int h = q.front().second;

            q.pop();
            if(x == n-1 && y == m-1){
                return true;
            }


            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx < 0 || nx >= n || ny < 0 ||  ny>= m){
                    continue;
                }

                int nh = h-grid[nx][ny];

                if(nh <= 0) continue;

                if(nh > bestH[nx][ny]){
                    bestH[nx][ny] = nh;
                    q.push({{nx,ny},nh});
                }

            }
        }

        return false;

    }
};