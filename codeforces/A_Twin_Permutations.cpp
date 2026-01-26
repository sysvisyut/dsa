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
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<n;i++){
            cout<<n+1-arr[i]<<" "; //gives a compliment of each
        }
        cout<<endl;
        
    }
}