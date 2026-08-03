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
    string s;
    cin>>s;

    ll n = s.size();

    ll maxi = 1;
    ll curr = 1;

    for(int i=0;i<n;i++){
        if(s[i] == s[i+1]){
            curr++;
            maxi = max(maxi,curr);
        }
        else curr = 1;
    }

    cout<<maxi;
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