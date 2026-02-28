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

    unordered_map<int,int> mp;

    void solve(vector<int>& nums,vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(auto &p : mp){
            if(p.second == 0) continue;

            temp.push_back(p.first);
            p.second--;
            solve(nums,temp);
            
            temp.pop_back();
            p.second++;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        for(int num: nums){
            mp[num]++;
        }
        vector<int> temp;

        solve(nums,temp);

        return ans;

    }
};