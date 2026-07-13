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

vector<int> ans;


void solve() {
    int n;
    cin>>n;

    vector<int> nums(n);
    int sum = 0;

    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    dp[0][0] = 1;

    //dp[i][j] -> represents if the sum j is possible using 0 to i coins

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){

            dp[i][j] = dp[i-1][j]; // if the curr sum is possible by skipping the ith coin

            if(j >= nums[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]]; // if the cum is possible by including ith coin
            }
        }
    }

    vector<int> ans;

    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            ans.push_back(i);
        }
    }

    int sz = ans.size();
    cout<<sz<<endl;

    for(int i=0;i<sz;i++){
        cout<<ans[i]<<" ";
    }

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