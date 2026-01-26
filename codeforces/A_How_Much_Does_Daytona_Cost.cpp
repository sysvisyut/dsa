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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool find = false;
        for(int i=0;i<n;i++){
            if(arr[i] == k){
                find = true;
            }
        }
        if(find){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}