#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    
    int n;
    cin>>n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + b[i];

    sort(a.rbegin(), a.rend());

    ll mx = 0;

    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i] == a[i+1]) continue;

        ll k = i + 1;
        ll cnt = upper_bound(p.begin(), p.end(), k) - p.begin() - 1;

        mx = max(mx, a[i] * cnt);
    }

    cout << mx << "\n";
}

int main() {
  
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}