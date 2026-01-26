#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (n < k) {
        cout << -1 << "\n";
        return;
    }
   
    if (n == k) {
        cout << 0 << "\n";
        return;
    }

    long long l = k;
    long long r = k;
    int ans = 0;
 
    while (r < n) {
        l = 2 * l - 1; 
        r = 2 * r + 1; 
        ans++;
    }

    if (n >= l && n <= r) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}