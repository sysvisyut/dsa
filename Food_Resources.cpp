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


bool check(int mid,vector<int>& arr, int m){
    ll cnt = 0;

    for(int i=0;i<arr.size();i++){
        cnt+=(arr[i]/mid);
    }

    return cnt >=m;
}
void solve() {
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>> arr[i];
    int l = 1;
    int r =0;

    if(!arr.empty()) r= *max_element(arr.begin(), arr.end());

    int ans = 0;
    while (l <= r){
        int mid = l+(r-l)/2;

        if(mid == 0) break;
        if(check(mid,arr,m)){
            ans = mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    cout<<ans<<endl;
}

int main() {
    fastio;

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}