#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    vector<int> nums(n,0);
    for (int i =1; i<n;i++) {
        nums[i] = nums[i-1] +(s[i]== s[i - 1]?1: 0);
    }
    
    while (q--) {
        int l,r,k;
        cin>>l>>r>>k;
        
        int c=nums[r-1]-nums[l-1];
        
        if ((c+1)/2 <= k) {
            cout<< "YES\n";
        } 
        else {
            cout <<"NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}