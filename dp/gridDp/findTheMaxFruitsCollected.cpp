#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int n;
    int dp1[1001][1001];
    int dp2[1001][1001];
    int h1(int i, int j, vector<vector<int>>& fruits){

        if(i >=n || j >=n || j < 0) return -1e9;

        if(dp1[i][j] != -1) return dp1[i][j];

        if(i == n-1 && j== n-1) return dp1[i][j] = 0; //already taken by c1

        if(i >=j) return -1e9;

        int diag1 = h1(i+1,j-1,fruits);
        int down = h1(i+1,j,fruits);
        int diag2 = h1(i+1,j+1,fruits);

        return dp1[i][j] = fruits[i][j]+ max({diag1,down,diag2});

    }
    int h2(int i, int j, vector<vector<int>>& fruits){

        if(i >=n || j >=n || i < 0) return -1e9;

        if(dp2[i][j] != -1) return dp2[i][j];

        if(i == n-1 && j== n-1) return dp2[i][j] = 0; //already taken by c1

        if(i <= j) return -1e9;

        int diag1 = h2(i-1,j+1,fruits);
        int down = h2(i,j+1,fruits);
        int diag2 = h2(i+1,j+1,fruits);

        return dp2[i][j] = fruits[i][j]+ max({diag1,down,diag2});

    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        
        /*
        c1 can only move diagonally

        c2 can only move within the upper diagonal part i.e (i < j),

        c3 can only move within the lower diagonal part i.e (i > j).

        */
        n = fruits.size();
        memset(dp1,-1, sizeof(dp1));
        memset(dp2,-1, sizeof(dp2));

        int c1 = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    c1+=fruits[i][j];
                }
            }
        }
        int c2 = h1(0,n-1,fruits);
        int c3 = h2(n-1,0,fruits);

        return c1+c2+c3;
    }
};