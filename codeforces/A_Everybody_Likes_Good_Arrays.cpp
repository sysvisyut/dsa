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
        
        int op=0;

        for(int i=0;i<n-1;i++){
            if((arr[i]%2 ==0 && arr[i+1]%2 == 0) || (arr[i]%2 !=0 && arr[i+1]%2 !=0)){
                op++;
            }
        }

        cout <<op<<endl;
        continue;
    }

    return 0;
}