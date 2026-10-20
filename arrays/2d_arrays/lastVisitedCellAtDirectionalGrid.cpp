#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;

        int ox =0;
        int oy =0;

        
        while(true){

                char move = grid[ox][oy];
                int nx = ox;
                int ny = oy;

                if(move == 'U'){
                    nx--;
                }
                else if(move == 'R'){
                    ny++;
                }
                else if(move == 'L'){
                    ny--;
                }
                else{
                    nx++;
                }
                
                if(nx < 0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] == 1){
                    return {ox,oy};
                }
                ox = nx;
                oy = ny;
                vis[nx][ny] = 1;
        }
        

        return {-1,-1};
    }
};