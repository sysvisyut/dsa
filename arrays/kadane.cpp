//Algorithm to find the maximum sum subarray
#include <iostream>
using namespace std;


void kadane(int n,vector<int>& arr){
    int currSum = arr[0];
    int maxSum = arr[0];

    for(int i=1;i<n;i++){
        currSum = max(arr[i],currSum+arr[i]);
        maxSum = max(maxSum,currSum);
    }

    cout<<"The maxinum of subarray is: "<<endl;

    cout<<maxSum<<endl;




}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    kadane(n,arr);
}