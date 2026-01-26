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
        
        int len = n;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]) len++;
        }
        
        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.push_back(arr[i]);
                ans.push_back(arr[i]);
            }
        }

        cout<<len<<endl;
        for(int i=0;i<len;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}