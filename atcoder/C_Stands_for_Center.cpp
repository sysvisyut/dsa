#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (!(cin >> s)) return 0;
    long long ans = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'C') {
            ans += min(i, n - 1 - i) + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}