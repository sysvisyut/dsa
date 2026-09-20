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
    
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>> nums[i];
    }

    vector<int> minif(n,INT_MAX);
    vector<int> minib(n,INT_MAX);

    minif[0] = nums[0];
    minib[n-1] = nums[n-1];

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[nums[i]] = i+1;
    }

    for(int i=1;i<n;i++){
        minif[i] = min(minif[i-1],nums[i]);
    }
    for(int i=n-2;i>=0;i--){
        minib[i] = min(minib[i+1],nums[i]);
    }
    vector<int> ans;
    for(int i=1;i<n-1;i++){
        if(minif[i-1] < nums[i] && nums[i] > minib[i+1]){
            cout<<"YES"<<"\n";
            cout<<mp[minif[i-1]]<<" "<<mp[nums[i]]<<" "<<mp[minib[i+1]];
            cout<<"\n";
            return;
        }
    }

    cout<<"NO"<<"\n";


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