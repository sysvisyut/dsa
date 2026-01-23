#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue; //skip duplicates
            }
            int l = i+1;
            int r = n-1;

            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];

                if(sum ==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if (sum < 0)l++; //since sorted nums[l] will inc the sum
                else r--; //sum is more than 0 so dec by adding less value i.e nums[r-1]
            }
        }

        return ans;  //time complexity O(n log n) + O(n × n) ~~ O(n^2);
    }
};