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



string helper(int i, int j, vector<vector<string>>& grid,int n){

    
    if(i == n-1 && j == n-1){
        return grid[i][j];
    }
    string down = "";
    string right = "";

    //when we at the last row or last col, we get empty string and its always smaller so should handle it seperately

    if(i == n-1){ // last row, only right is possible
        return grid[i][j]+helper(i,j+1, grid,n);
    }
    if(j == n-1){ // last col, only down is possible
        return grid[i][j]+helper(i+1,j, grid,n);
    }
    
    down = grid[i][j]+ helper(i+1,j, grid, n);
    
    right = grid[i][j]+helper(i,j+1, grid,n);
    return min(down, right);
}

void solve() {
    int n;
    cin>> n;

    vector<vector<string>> grid(n, vector<string>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    cout<< helper(0,0, grid,n);
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