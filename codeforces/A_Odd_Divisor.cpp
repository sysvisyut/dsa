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
    ll n;
    cin>>n;

    while(n%2 == 0){
        n/=2;
    }

    if(n > 1){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
    
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