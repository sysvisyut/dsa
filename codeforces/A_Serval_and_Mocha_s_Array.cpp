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
        bool flag =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(gcd(arr[i],arr[j]) <= 2) flag =1;
            }
        }

        if(flag){
            cout<<"Yes"<<endl;
            continue;
        }
        else{
            cout<<"No"<<endl;
            continue;
        }
    }

    return 0;
}