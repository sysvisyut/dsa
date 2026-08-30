#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n =nums.size();

        int max_len = 1;

        unordered_map<int,int> mp;

        while(r < n){
            mp[nums[r]]++;

            while(mp[nums[r]] >k && l<=r){
                
                mp[nums[l]]--;
                l++;
            }
            max_len = max(max_len, r-l+1);
            r++;
        }

        return max_len;
    }
};