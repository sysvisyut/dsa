#include <iostream>
using namespace std;


void solve(){
    long long n;
    cin>>n;
    if(n%2!=0 || n<4){
        cout<<-1<<endl;
        return;
    }
    long long maxi = n/4;

    long long mini = (n+6-1)/6; //ceil division

    cout<<mini<<" "<<maxi<<endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}