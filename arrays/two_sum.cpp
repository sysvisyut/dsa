#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; 
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }

        for(int i=0;i<n;i++){
            int need = target-nums[i];
            if(mp.find(need) != mp.end() && mp[need] != i){ //ensure to check if same index is not selected
                return{mp[need],i};
            }
            
        }
        return {-1,-1};
    }
}; 