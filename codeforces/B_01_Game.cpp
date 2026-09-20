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
    
    string s;
    cin>>s;

    int n = s.size();
    
    int cnt = 0;

    stack<char> st;

    
    for(char ch: s){
        if(!st.empty() && st.top() != ch){
            st.pop();
            cnt++;
        }else{
           st.push(ch); 
        }
    }
    if(cnt&1){
        cout<<"DA"<<"\n";
    }
    else{
        cout<<"NET"<<"\n";
    }

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