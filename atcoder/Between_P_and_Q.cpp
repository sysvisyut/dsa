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


int n;
int cnt = 0;

void generate(vector<int>& curr, vector<bool>& used,const vector<int>& p, const vector<int>& q, int n) {

    if (curr.size() == n) {
        if (curr>p && curr<q)

            cnt++;

        return;
    }

    for (int i=1;i<=n;i++){

        if (!used[i]) {

            used[i] = true;
            curr.push_back(i);
            generate(curr, used, p, q, n);
            curr.pop_back();
            used[i] = false;
        }
    }

}

void solve() {

    cin>>n;

    vector<int>p(n);
    vector<int>q(n);

    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    
    if(p > q){
        cout<<0<<endl;
        return;
    }

    vector<int> curr;
    vector<bool> used(n+1,false);

    generate(curr,used,p,q,n);

    cout << cnt << endl;



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