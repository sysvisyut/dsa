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

void solve() {
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){

            if(i == j){
                dp[i][j] = nums[i];
                continue;
            }
            if(j-i == 1){
                dp[i][j] = max(nums[i], nums[j]);
                continue;
            }
            ll x = (i+2 <= j) ?dp[i+2][j] :0;
            ll y = (i+1 <= j-1)?dp[i+1][j-1] :0;
            ll z = (i<= j-2)? dp[i][j-2]: 0;


            ll choice1 = nums[i]+ min(x,y);
            ll choice2 = nums[j] + min(y,z);
            dp[i][j] = max(choice1,choice2);
        }
    }

    cout<< dp[0][n-1];
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