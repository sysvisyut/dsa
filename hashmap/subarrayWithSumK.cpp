#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        
        int sum = 0;
        int cnt = 0;
        mp[0] =1; // base case
        for(int i=0;i<n;i++){
           sum+=nums[i];

           if(mp.count(sum-k)){
                cnt+=mp[sum-k];
           }
           mp[sum]++;

        }

        return cnt;
    }
};