#include <iostream>
#include <vector>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        int zc=0,oc=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            int n;
           
        }

        for(int i=0;i<n;i++){
            if(arr[i] == 1) oc++;
            if(arr[i] == 0) zc++;
        }
        long long ans = 1ll*oc*(1ll << zc);

        cout<<ans<<endl;
    }
}

