#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        int n = arr.size();
        int sum = 0;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxLen = i+1;
            }
            else{
                if(mp.find(sum) != mp.end()){
                    maxLen = max(i-mp[sum],maxLen);
                }
                else{
                    mp[sum]= i;
                }
            }
        }
        
        return maxLen;
    }
};