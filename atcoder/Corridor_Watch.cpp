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
#include <climits>
#include <numeric>
#include <iomanip>

using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n,d;
    cin>>n>>d;
    string s;
    cin>>s;

    vector<bool> g(n,false);


    for(int i=0;i<n;i++){
        if(s[i] == '.' && g[i] == 1) continue;
        
        if(s[i] == 'G'){
            int l = max(0,i-d);
            int r = min(n-1,i+d);
            for(int j = l; j<=r;j++){
                g[j] =1;
                
            }
        }

    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(g[i] == 0){
            ans++;
        }
    }

    cout<<ans<<endl;

}

int main() {
    fastio;

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}