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
    ll n,k;
    cin>>n>>k;

    vector<ll> nums(n*k);

    for(int i=0;i<n*k;i++){
        cin>>nums[i];
    }

    ll sum = 0;

    ll i = (n*k);

    while(k--){
        i-=(n/2+1);
        sum+= nums[i];
    }

    cout<<sum<<"\n";
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