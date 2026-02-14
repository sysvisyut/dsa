#include <iostream>

using namespace std;
typedef long long ll;


void solve(){
    ll a, b, c;
    cin >> a >> b >> c;

    bool ok = false;

  
    ll new_a = 2*b - c;
    if (new_a > 0 && a != 0 && new_a % a == 0) ok = true;

    
    if ((a + c) % 2 == 0) {
        ll new_b = (a + c) / 2;
        if (new_b > 0 && b != 0 && new_b % b == 0) ok = true;
    }

    
    ll new_c = 2*b - a;
    if (new_c > 0 && c != 0 && new_c % c == 0) ok = true;

    cout << (ok ? "YES\n" : "NO\n");
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
