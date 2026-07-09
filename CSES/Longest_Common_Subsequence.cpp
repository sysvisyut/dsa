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
    int n,m;
    cin>>n>>m;

    vector<int> nums1(n), nums2(m);

    for(int i=0;i<n;i++) cin>>nums1[i];
    for(int i=0;i<m;i++) cin>>nums2[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(nums1[i] == nums2[j]){
                dp[i][j] = 1+dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout<< dp[0][0]<<endl;

    vector<int> lcs;
    int i=0,j=0;

    while(i < n && j < m){
        if(nums1[i] == nums2[j]){
            lcs.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }


    for(int i=0;i< lcs.size(); i++){
        cout<< lcs[i]<<" ";
    }

    
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