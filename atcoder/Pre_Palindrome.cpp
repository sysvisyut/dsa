#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    
    ll ans = 0;
    int n = s.size();
    
    for (int i=0;i<n;i++) {
        int k= 0;
        int l = i, r = i;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                k++;
            }
            if (k>1) {
                break;
            }
            ans++;
            l--;
            r++;

        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        int k=0;
        int l=i, r = i+1;
        while (l>=0 && r<n) {
            if (s[l] != s[r]) {
                k++;
            }
            if (k>1) {
                break;
            }
            ans++;
            l--;
            r++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}