#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){

        long long a,b,n;
        cin>>a>>b>>n;
        vector<long long>arr(n);
    
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    
        long long sum =b;
    
        for(int i=0;i<n;i++){
            sum+= min(arr[i],a-1);
        }
    
        cout<<sum<<endl;
        continue;
    }
    return 0;
}