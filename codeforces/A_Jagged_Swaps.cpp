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
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int mini = *min_element(arr.begin(),arr.end());
        if(arr[0] != mini){
            cout <<"NO"<<endl;
            continue;
        } 
        else{
            cout<<"YES"<<endl;
        }
            
    }
}