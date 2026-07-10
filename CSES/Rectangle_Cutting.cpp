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
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1, vector<int>(b+1,0));

   
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){

            if(i == j){ // base case: when the problem is already a sqaure and no cuts are needed
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = INT_MAX;


            //try all vertical cuts
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }

            //try all horizontal cuts
            for(int k =1;k<i;k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
        }
    }

    cout<<dp[a][b];
   
    
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