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
    int n;
    cin>>n;
    string s;
    cin>>s;


    int maxi = 0;
    int curr = 0;

    for(int i=0;i<n;i++){
        if(s[i] == '#'){
            curr++;
            maxi = max(maxi,curr);
        }
        else if(s[i] == '*'){
            curr = 0;
        }
    }

    cout<< (maxi+1)/2 << endl;
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