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

        long long neg=0;
        long long pos=0;

        for(int i=0;i<n;i++){
            if(arr[i]<0) neg++;
            else pos++;
        }
        long long operations = 0;
        while(neg%2 !=0 || neg>pos){
            operations++;
            neg--;
            pos++;
        }

        cout<<operations<<endl;
            
        
        
    }
}