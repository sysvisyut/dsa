#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
   
    sort(b.begin(), b.end());
    
    ll maxi = 0;
    int last = 0;
    
   
    for (int i = 0; i < m; i++) {
        int curr= b[i];
        ll sum= 0;
        
        for (int j =last+1;j<= curr;j++) {
            sum += a[j];
        }
        
        maxi += abs(sum);
        last =curr;
    }
    
    for (int j = last+1; j<=n; j++) {
        maxi += a[j];
    }
    cout << maxi<< "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}