#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:

typedef long long ll;

    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        int l=0,r=0;

        ll ans = -1;
        ll sum = 0;
       
        unordered_set<int> st;

        while(r < n){
            while(st.find(nums[r]) != st.end()){
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            if(st.find(nums[r]) == st.end()){
                st.insert(nums[r]);
                sum+=nums[r];
            }

            if(r-l+1 == k){
                ans = max(ans,sum);
                sum-=nums[l];
                st.erase(nums[l]);
                l++;
            }
            r++;

        }

        return ans == -1 ? 0 : ans;
    }
};