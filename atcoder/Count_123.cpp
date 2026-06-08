#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353, m = 2000005;
long long f[m], inv[m];

long long p(long long b, long long e) {
    long long r = 1;
    for (;e; e>>= 1, b = b*b % mod) {
        if (e & 1) r = r * b % mod;
    }
    return r;
}

long long c(int n, int r) {
    return (r < 0 || r > n) ? 0 : f[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {
    
    f[0] = 1;
    for(int i = 1; i < m; ++i) f[i] = f[i - 1] * i % mod;
    inv[m - 1] = p(f[m - 1], mod- 2);


    for(int i = m - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    };
    
    int x1,x2,x3;
    cin >> x1>>x2>>x3;
    
    long long ans = 0;
    for (int a = 1; a <= min(x1, x2); ++a) {
        long long t = c(x2 + 1, a) * c(x1-1, a- 1)%mod * c(x2+x3-a, x2-a)%mod;
        ans =(ans + t)%mod;
    }
    cout <<ans<<"\n";
    return 0;


}