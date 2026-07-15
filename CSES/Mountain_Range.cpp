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

    vector<pair<int,int>> nums;

    for(int i=0;i<n;i++){
        int h;
        cin>>h;

        nums.push_back({h,i});
    }

    
    vector<int> nge(n), pge(n);
    
    stack<int> st;
    
    for(int i= n-1;i >=0;i--){
        while(!st.empty() && nums[st.top()].first <= nums[i].first){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(int i=0;i < n;i++){
        while(!st.empty() && nums[st.top()].first <= nums[i].first){
            st.pop();
        }
        if(st.empty()){
            pge[i] = -1;
        }
        else{
            pge[i] = st.top();
        }
        st.push(i);
    }
    
    sort(nums.rbegin(), nums.rend());
    vector<int> dp(n+1,0);

    for(int i=0;i<n;i++){

        int idx = nums[i].second;

        dp[idx] = 1;

        if(nge[idx]!= -1){
            dp[idx] = max(dp[idx], 1+dp[nge[idx]]);
        }
        if(pge[idx] != -1){
            dp[idx] = max(dp[idx], 1+dp[pge[idx]]);
        }
    }


    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }


    cout<<ans<<endl;
    



   
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