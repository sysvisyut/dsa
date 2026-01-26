#include <iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,x;
        cin>>n>>s>>x;

        vector<int>arr(n);
        int sum =0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }

        if(sum == s){
            cout<<"YES"<<endl;
            continue;
        }
        else if(sum >s){
            cout<<"NO"<<endl;
            continue;
        }
        int need = s-sum;

        if(need%x == 0){
            cout<<"YES"<<endl;
            continue;
        } 
        else{
            cout<<"NO"<<endl;
            continue;
        }
    }
}