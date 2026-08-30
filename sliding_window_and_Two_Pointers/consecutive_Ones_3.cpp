#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        int r= 0;
        int maxLen = INT_MIN;

        while(r<n){
            if(k>=0 && nums[r] == 0){
                k--;
            }
           
            while(k<0){
                if(nums[l] == 0){
                    k++;
                }
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};