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
        cin>>nums[i];
    }

    unordered_map<int,int> mp;
    int oc = 0;
    int ec1 = 0;
    int ec2 = 0;
    
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        mp[nums[i]]++;
        if(nums[i]&1){
            oc++;
        }
        else{
            if((nums[i]/2) & 1){
                ec1++;
            }
            else{
                ec2++;
            }
        }
    }

    cout<< max({oc,ec1,ec2})<<endl;

    

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