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

        long long curr = 0;
        for(int i=0;i<n;i++){
            long long num;

            cin>>num;
            if(num>0){
                curr+=num;
            }
            else{
                long long temp= min(curr,abs(num));
                curr-=temp;
            }

        }
        cout<<curr<<"\n";
        
    }
    return 0;
}
