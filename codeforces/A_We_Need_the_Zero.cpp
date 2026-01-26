#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

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

        if(n%2 ==0){
            int res = 0;
            for(int i=0;i<n;i++){
                res^=arr[i];
            }

            if(res == 0){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        else{
            int res = 0;
            for(int i=0;i<n;i++){
                res^=arr[i];
            }
            cout<<res<<endl;
            continue;
        }
    }
}