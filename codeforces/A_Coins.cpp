#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;

        if(n%2 ==0 || (n-k)%2 == 0){
            cout<<"yes"<<endl;
            continue;
        }
        else{
            cout<<"no"<<endl;
            continue;
        }
    }
}