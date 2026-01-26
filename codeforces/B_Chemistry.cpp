#include <iostream>
#include <map>

using namespace std;

string solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int odd_cnt=0;

    for(auto it: mp){
        if(it.second%2 !=0) odd_cnt++;
    }

    if(odd_cnt-k <= 0 || odd_cnt-k == 1){
        return "YES";
    }
    else{
        return "NO";
    }


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
    return 0;
}