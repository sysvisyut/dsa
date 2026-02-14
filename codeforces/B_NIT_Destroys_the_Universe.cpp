#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int cnt=0;
    int i=0;
   
    while(i<n){
        if(arr[i]==0)i++;
        else{
            while(i<n && arr[i]!=0){
                i++;
            }
            cnt++;
        }

    }
    if(cnt ==0) cout<<0<<endl;
    else if(cnt ==1) cout<<1<<endl;
    else cout<<2<<endl;

}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}