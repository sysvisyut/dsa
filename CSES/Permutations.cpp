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
    ll n;
    cin>>n;

    if(n == 1){
        cout<<1;
        return;
    }

    if(n<4){
        cout<<"NO SOLUTION";
        return;
    }



    vector<ll> ans;
    vector<ll> eve;

    for(int i=1;i<=n;i++){
        if(i&1){
            ans.push_back(i);
        }
        else eve.push_back(i);
    }
    
    for(int i=0;i<eve.size();i++){
        cout<<eve[i]<<" ";
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    
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