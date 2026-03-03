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
    unordered_set<int> st;
    void solve(vector<int>& nums,vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,temp);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp);

        return ans;
    }
};

//optimal approach: using inplace swap:

class Solution {
public:
    vector<vector<int>> ans;

    void helper(int ind,vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            helper(ind+1,nums);
            swap(nums[ind],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0,nums);
        return ans;


    }
};