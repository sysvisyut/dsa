#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;

    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> arr(n);
        vector<ll> prefix(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        prefix[0] = arr[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+arr[i];
        }

        while(q--){
            ll l,r,k;
            cin>>l>>r>>k;
            r--; //0 indexing
            l--;
            ll que = (r-l+1)*k;
            ll old;
            if (l == 0) old = prefix[r];
            else old = prefix[r] - prefix[l-1];
            ll sum = prefix[n-1]-old+que;
            
            if(sum%2 !=0 ){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
            }
           
        }
    }
    return 0;
}