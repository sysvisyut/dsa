#include <iostream>

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
        int maxi = *max_element(arr.begin(),arr.end());

        cout<<n*maxi<<endl;
        
        
    }
    return 0;
}