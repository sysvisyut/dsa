#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       long long a,b,c,d;
       cin>>a>>b>>c>>d;
        if(d<b || (a+(d-b))<c){
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<2*(d-b)+(a-c)<<endl;
            continue;
        }
    }
}