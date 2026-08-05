#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l=0;
        int r=1;

        int cnt = 0;
        while(l<n && r<n){
            int val = nums[r]-nums[l];
            if(l==r || val< k){
                r++;
            }
            else if(val >k){
                l++;
            }
            else{
                cnt++;
                l++;
                while(l < n && nums[l]==nums[l-1]) l++;
            }
        }

        return cnt;
    }
};