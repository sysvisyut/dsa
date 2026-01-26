#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int gcd(int a, int b){
    if(b==0) return a;

    else return gcd(b, a%b);
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
       
        int curr = 0;
        int k = 0;

        for(int i=0;i<n;i++){
            curr = abs(i-arr[i]+1);
            k = gcd(curr,k);
        }
        cout<<k<<endl;
        
    }
}