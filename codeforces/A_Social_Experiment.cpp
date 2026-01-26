#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(n<=3){
            cout<<n<<endl;
            continue;
        }

        else{
            cout<<n%2<<endl;
            continue;
        }
   
    }
}