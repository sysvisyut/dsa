#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main(){
    int t;
    cin>> t;

    while(t--){
        int x,k;
        cin>>x>>k;

        if( x%k != 0){
            cout<<1<<endl;
            cout<<x<<endl;
            continue;
        }

        else{
            cout<<2<<endl;
            cout<<x-1<<" "<<1<<endl;
            continue;
        }
    }
}