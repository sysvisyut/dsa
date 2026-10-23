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

    vector<ll> secMins;

    ll mini = LLONG_MAX;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;

        vector<ll> nums(m);

        for(int j=0;j<m;j++){
            cin>>nums[j];
        }

        sort(nums.begin(), nums.end());

        secMins.push_back(nums[1]);
        mini = min(mini,nums[0]);
    }

    sort(secMins.begin(), secMins.end());

    ll sum = accumulate(secMins.begin(), secMins.end(),0LL);

    ll ans = sum+mini-secMins[0];

    cout<<ans<<"\n";
}

int main() {
    fastio;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}