#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int n;

ll helper(int el, int sum, int target, vector<vector<int>> &dp) {

    if (sum > target)
        return 0;

    if (el > n)
        return sum == target;

    if (dp[el][sum] != -1)
        return dp[el][sum];

    ll take = helper(el + 1, sum + el, target, dp);
    ll skip = helper(el + 1, sum, target, dp);

    return dp[el][sum] = (take + skip) % MOD;
}

ll modPow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    ll total = 1LL * n * (n + 1) / 2;

    if (total & 1) {
        cout << 0;
        return 0;
    }

    int target = total / 2;

    vector<vector<int>> dp(n + 2, vector<int>(target + 1, -1));

    ll ways = helper(1, 0, target, dp);

    cout << ways * modPow(2, MOD - 2) % MOD;
}