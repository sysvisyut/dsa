#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int hgcd(int a, int b){

    if(b ==0){
        return a;
    }

    return hgcd(b,a%b);
}
void solve() {
    int n,x,y;
    cin>>n>>x>>y;



    int d = hgcd(x, y);

    bool ok = true;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;

        if(abs(p-i) % d != 0){
            ok = false;
        }
    }

    if(ok) cout<<"YES"<<endl;


    else cout<<"NO"<<endl;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}