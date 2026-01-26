#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        vector<ll> arr1(n),arr2(n),best(n);
        //vector<pair<int,int>> que(q);

        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++) cin>>arr2[i];
        // for(int i=0;i<q;i++){
        //     cin>>que[i].first >> que[i].second;
        // }

        for(int i=0;i<n;i++){
            best[i] = max(arr1[i],arr2[i]); //op1
        }


        for (int i = n - 2; i >= 0; i--) {
        best[i] = max(best[i], best[i + 1]);
        }   

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + best[i];
        }

        while(q--){
            int l,r;
            cin>>l>>r;
         

            cout << pref[r] - pref[l - 1] << (q == 0 ? "" : " ");

        }
        cout<<endl;

        
      

    }
}
