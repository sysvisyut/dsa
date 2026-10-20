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
    int n,k;
    cin>>n>>k;

    vector<ll> nums(n);

    int ec = 0;

    for(ll i=0;i<n;i++){
        cin>>nums[i];
        
    }

    ll ans = LLONG_MAX;

    for(int i=0;i<n;i++){
        if((nums[i]&1) == 0) ec++;

        ans = min(ans, (ll)((k - (nums[i] % k)) % k));

    }
    if(k == 4){
        if(ec == 1){
            ans = min(ans,1LL);
        }
        else if(ec >=2){
            ans = min(ans,0LL);
        }
        else if(ec == 0){
            ans = min(ans,2LL);
        }
    }

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