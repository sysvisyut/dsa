#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>curr,int index, vector<int>& nums){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            helper(curr,i+1,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        helper(curr,0,nums);
        return ans;
    }
};