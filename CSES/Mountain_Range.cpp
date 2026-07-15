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

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    reverse(nums.begin(),nums.end());

    vector<int> lis;

    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);

        if(it == lis.end()){
            lis.push_back(nums[i]);
        }
        else{
            *it = nums[i];
        }
    }

    cout<<lis.size();
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