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

    vector<ll> nums(n);

    for(int i=0;i<n;i++) cin>> nums[i];

    ll ans = 0;

    for(int i=1;i<n;i++){
        ll diff = nums[i]-nums[i-1];

        if(diff >=0) continue;

        ans+= abs(diff);
        nums[i]+= abs(diff);
    }

    cout<<ans;



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