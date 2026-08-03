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

    vector<ll> nums(n-1);

    for(int i=0;i<n-1;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    bool ok = false;

    for(int i=0;i<n-1;i++){
        if(nums[i]!= i+1){
            cout<<i+1;
            ok = true;
            return;
        }
    }

    if(!ok){
        cout<<n;
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