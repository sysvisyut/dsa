#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int tot = m*n;

        k%=tot;
        
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldIdx = i*n +j; //convert into 1d array indexing
                
                int shiftedIdx = (oldIdx+k)%tot;

                int nr = shiftedIdx/n;
                int nc = shiftedIdx%n;

                ans[nr][nc] = grid[i][j];
            }
        }

        return ans;
    }
};