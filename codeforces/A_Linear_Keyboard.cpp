#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        map<char, int> mp;
        string s, ss;

        cin >> s >> ss;

        for(int i = 0; i < s.size(); i++){
            mp[s[i]] = i + 1;
        }
        int ans = 0, curr = mp[ss[0]];

        for(int i = 1; i < ss.size(); i++){
            ans += abs(mp[ss[i]] - curr);
            curr = mp[ss[i]];
        }

        cout << ans << endl;

    }
}
