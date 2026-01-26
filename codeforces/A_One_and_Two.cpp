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
        int twos =0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
        }
        for(int i=0;i<n;i++){
            if(arr[i] == 2) twos++;
        }
        if(twos%2 !=0){
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;

        for(int i=0;i<n;i++){
            if(arr[i] == 2 ) cnt++;

            if(cnt == twos/2){
                cout<<i+1<<endl;
                break;
            }
        }
        
    }
}