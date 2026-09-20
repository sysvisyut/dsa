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

    string s;
    cin>>s;

    int n = s.size();

    int oc = 0;
    int zc = 0;

    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            oc++;
        }
        else{
            zc++;
        }
    }

    int t = 0;

    for(int i=0;i<n;i++){
        if(s[i] == '1' && zc > 0){
            t++;
            zc--;
        }
        else if(s[i] == '0' && oc > 0){
            t++;
            oc--;
        }
        else{
            break;
        }
    }

    cout<<n-t<<"\n";
    
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