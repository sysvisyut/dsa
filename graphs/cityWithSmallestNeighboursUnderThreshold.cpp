#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            mat[i][i] = 0;
        }
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX){
                        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
        int mini = INT_MAX;
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(mat[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= mini){
                mini = cnt;
                ans=i;
            }
        }
        return ans;
    }
};