#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, n;
    cin >> x >> n;

    if (x % 2 == 0) {
        if (n % 4 == 1) x -= n;
        else if (n % 4 == 2) x += 1;
        else if (n % 4 == 3) x += n + 1;
    }
    else {
        if (n % 4 == 1) x += n;
        else if (n % 4 == 2) x -= 1;
        else if (n % 4 == 3) x -= n + 1;
    }

    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}