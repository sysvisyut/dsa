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

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> o(n+1, 0), x(n+1, 0);
    vector<int> xPos;

    for (int i = 1; i <= n; i++) {
        o[i] = o[i - 1];
        x[i] = x[i - 1];

        if (s[i - 1] == 'o')
            o[i]++;
        else {
            x[i]++;
            xPos.push_back(i); 
        }
    }

    int tot = xPos.size();

    for (int k=1; k<=n; k++) {
        int poss = o[k];

        if (poss == 0) {
            cout << k << '\n';
            continue;
        }

        int t = x[k] + poss;

        if (t > tot) {
            cout << n << '\n';
        } else {
            cout << xPos[t-1] << '\n';
        }
    }

    return 0;
}