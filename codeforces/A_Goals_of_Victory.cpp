#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n-1);
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        int neg =0;
        int pos =0;
        for(int i=0;i<n-1;i++){
            if(arr[i] < 0) neg+= arr[i];

            else pos+=arr[i];
        }
        int ans =0;
        ans = (-neg)-pos;

        cout<<ans<<endl;
    }
    return 0;
}