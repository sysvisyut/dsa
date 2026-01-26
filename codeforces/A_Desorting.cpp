#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
            cin>>arr[i];
       }
       int mini = INT_MAX;
       for(int i=1;i<n;i++){
            mini = min(arr[i]-arr[i-1],mini);
       }
       if(mini ==0){
            cout<<1<<endl;
            continue;
       }

       if(mini < 0){
            cout<<0<<endl;
            continue;
       } 

       
        int ans = (mini/2)+1;

         cout<<ans<<endl;
       
    }
}
