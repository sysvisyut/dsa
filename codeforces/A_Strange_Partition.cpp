#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int t;

    cin>>t;
   

    while(t--){
        ll n,x;
        cin>>n>>x;

        ll maxi=0,mini=0;

        
        for(int i=0;i<n;i++){
            int num;
            cin>> num;
            maxi+= (num+x-1)/x;
            mini+= num;
        }
        

        mini = (mini+x-1)/x;

        cout<<mini<<" "<<maxi<<endl;

    }
    return 0;
}