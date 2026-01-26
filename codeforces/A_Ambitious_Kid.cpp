#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = INT_MAX;
    int temp = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            ans=0;
            break;
        }
        temp = abs(0-arr[i]);
        ans = min(ans,temp);
    }

    cout<<ans<<endl;
}