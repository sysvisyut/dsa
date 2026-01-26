#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int maxi = 0;
    int curr = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i == 0) {
            curr = 1;
        } else {
            if (a[i] == a[i-1] + 1) {
                curr++;
            } 
            else if(a[i] == a[i-1]){
                continue;
            }
            else {
                curr = 1;
            }
        }
        maxi = max(maxi, curr);
    }

    cout << maxi << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}