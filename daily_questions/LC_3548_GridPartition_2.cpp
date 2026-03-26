#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef long long ll;
    ll total = 0;
    bool check(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                st.insert(grid[i][j]);
                top+=grid[i][j];
                
            }
            ll down = total-top;
            ll diff = top-down;

            if(diff == 0) return true;
            if(diff == (ll)grid[0][0]) return true;
            if(diff == (ll)grid[0][n-1]) return true;
            if(diff == (ll)grid[i][0]) return true;

            if(i>0 && n>1 && st.count(diff)) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }

        if(check(grid)){
            return true;
        }
        reverse(grid.begin(),grid.end());

        if(check(grid)){
            return true;
        }

        reverse(grid.begin(),grid.end());

        vector<vector<int>> trans(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                trans[j][i] = grid[i][j];
            }
        }
        if(check(trans)) return true;

        reverse(trans.begin(),trans.end());

        if(check(trans)) return true;

        return false;

        
    }
};