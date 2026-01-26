#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        string cur = x;
        int ans = 0;

        while (cur.size() < s.size()) {
            cur += cur;
            ans++;
            if (cur.size() > 2 * s.size()) break;
        }

        if (cur.find(s) == string::npos) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}