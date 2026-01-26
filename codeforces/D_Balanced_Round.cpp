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

        for (int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        if(arr.size() == 1){
            cout<<0<<endl;
            continue;
        }
        int i=0;
        int j=1;

        int max_len=1;
        int curr =1;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1]) > k){
                curr = 1;
            }
            else{
                curr++;
                max_len = max(max_len,curr);
            }
        }

        cout<<n-max_len<<endl;
    }
}