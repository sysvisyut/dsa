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
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int maxi = *max_element(arr.begin(),arr.end());
        vector<long long>b,c;
        for(int i=0;i<n;i++){
            if(arr[i] == maxi){
                c.push_back(arr[i]);
            }
            else{
                b.push_back(arr[i]);
            }
        }

        if(c.size() == n){
            cout<<-1<<endl;
            continue;
        } 
        else{
            cout<<b.size()<<" "<<c.size()<<endl;
            for(int i=0;i<b.size();i++){
                cout<<b[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<c.size();i++){
                cout<<c[i]<<" ";
            }
        }
                   
    }
}