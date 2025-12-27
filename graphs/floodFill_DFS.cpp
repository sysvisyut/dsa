#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(int r, int c,vector<vector<int>>& image,vector<vector<int>>& ans, int iniColor,int color){
        ans[r][c] = color;
        int row = image.size();
        int col = image[0].size();
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};

        for(int i=0;i<4;i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];

            if(nrow <row && nrow>=0 && ncol<col && ncol>=0 && image[nrow][ncol]==iniColor &&
            ans[nrow][ncol]!= color){
                dfs(nrow,ncol,image,ans,iniColor,color);

            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        dfs(sr,sc,image,ans,iniColor,color);
        return ans;

    }
};