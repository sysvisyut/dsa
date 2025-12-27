#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        int row = image.size();
        int col = image[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            ans[r][c] = color;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow < row && nrow >=0 && ncol < col && ncol>=0 && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                    q.push({nrow,ncol});
                }
            }
        }

        return ans;
    }
};