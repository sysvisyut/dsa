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

using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    int sz =s.size();

    int ans = 0;

    for(int i=0;i<sz-k+1;i+=k){
        bool ok = false;
        for(int j=i;j<i+k;j++){
            if(s[j] == '0'){
                ok = true;
            }
        }
        if(!ok) ans++;
    }

    cout<<ans<<endl;
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