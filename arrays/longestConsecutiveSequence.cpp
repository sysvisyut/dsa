#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int currMax = 1;
        if(nums.size() == 0) return 0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1] == 1){
                currMax++;
                maxLen = max(maxLen,currMax);
            }
            else if(nums[i]-nums[i-1] == 0){
                continue;
            }
            else{
                currMax = 1;
            }
        }

        return maxLen;
    }
};