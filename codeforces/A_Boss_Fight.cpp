#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    unordered_map<int,int>mp;
    int sum= 0;

    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
        sum+=a[i];
    }

    int maxi = 0;
    int val = 0;

    for(auto it :mp){
        if(it.second > maxi){
            maxi =it.second;
            val = it.first;
        }
    }

    int left= n-maxi;

    if(maxi <= left+2){
        cout<<sum<<endl;
    }else{
        int ans = (sum-maxi*val)+(left+2)*val;
        cout<< ans<<endl;
    }
}

int main() {
    fastio

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}