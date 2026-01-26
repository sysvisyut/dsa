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
        int temp =0;
        int maxi =0;

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                temp++;
                maxi = max(maxi,temp);
            }
            else{
                temp = 0;
            }
        }

        cout<<maxi<<endl;
        
    }
}