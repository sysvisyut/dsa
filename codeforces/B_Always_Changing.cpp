#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
string s;
vector<vector<int>> dp;

int f(int i, int exp) {
    if (i == n) return 0;

    if (dp[i][exp] != -1) return dp[i][exp];

    int res = f(i+1,exp);

    if (s[i]-'0' == exp) res = max(res, 1 + f(i+1,1-exp));


    return dp[i][exp] = res;
}

void solve() {
    cin>>n>>s;
    int o=0, z=0;

    for (char c : s){
        if(c=='1'){
            o++;
        }
        else{
            z++;
        }
    }

    int d = z-o;
    if (abs(d) > 2) {
        cout << -1 <<endl;
        return;
    }

    dp.assign(n, vector<int>(2, -1));
    
    int p0 = f(0, 0);
    int p1 = f(0, 1);
    int maxi = -1;

    for (int diff = -1; diff <= 1; ++diff) {
        if (diff >= d - 1 && diff<= d + 1) {
            
            if (diff == 1 && p0 > 0) maxi = max(maxi, p0 % 2 == 1 ? p0 : p0 - 1);

            else if (diff == 0) {
                if (p0 > 0) maxi = max(maxi, p0 % 2 == 0 ? p0 : p0 - 1);

                if (p1 > 0) maxi = max(maxi, p1 % 2 == 0 ? p1 : p1 - 1);

                maxi = max(maxi, 0);
            }
            else if (diff == -1 && p1>0) {
                maxi = max(maxi, p1%2 == 1 ? p1 : p1-1);
            }
        }
    }

    cout << (maxi == -1 ? -1 : n-maxi) <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}