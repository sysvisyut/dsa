#include <iostream>
#include <vector>

using namespace std;

int sumUsingPrefix(int n,int l,int r, vector<int>arr){
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    if(l==0) return prefix[r];
    else return prefix[r]-prefix[l-1];

}
int main(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The sum of the subarray from "<< l << "to "<< r << "is: ";
    cout<<sumUsingPrefix(n,l,r,arr);

    
}