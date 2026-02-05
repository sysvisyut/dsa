#include <iostream>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];
    int mini = *min_element(arr.begin(),arr.end());
    int maxi = *max_element(arr.begin(),arr.end());
    if(arr[0] ==mini || arr[n-1]==maxi){
        cout<<maxi-mini<<endl;
        return;
    }
    else{
        int curr=INT_MIN;
        int final =INT_MIN;
        int max1 = INT_MIN;
        int min1 =INT_MAX;
        for(int i=1;i<n;i++){
            max1 = max(arr[i],max1);

        }
        for(int i=0;i<n-1;i++){
            min1 = min(arr[i],min1);
        }
        max1 = max1-arr[0];
        min1 = arr[n-1]-min1;
        final =max(max1,arr[n-1]-arr[0]);
        final = max(final,min1);
        for(int i=0;i<n-1;i++){
            curr = max(curr,arr[i]-arr[i+1]);
            
        }
        final = max(final,curr);
        
        cout<<final<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}