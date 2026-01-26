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
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;          //breaking point
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            for(int x : nums) cout << x << " ";
            cout << "\n";
            continue;
        }
        for(int i=n-1;i>index;i--){
            if(nums[i]> nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index+1,nums.end());

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
