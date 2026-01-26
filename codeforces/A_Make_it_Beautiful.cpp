#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int gcd(int a,int b){
    return b==0 ? a: gcd(b, a%b);
}
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
        sort(arr.begin(),arr.end());

        int maxi = *max_element(arr.begin(),arr.end());
        int mini = *min_element(arr.begin(),arr.end());

        if(maxi == mini){
            cout<<"NO"<<endl;
            continue;
        }

        else{
            cout<<"YES"<<endl;
            cout<<maxi<<" ";
            for(int i=0;i<n-1;i++){
                cout<<arr[i]<<" ";
            }

            cout<<endl;
            continue;
        }
    }

    return 0;
}