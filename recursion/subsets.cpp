#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
vector<vector<int>>ans;
public:
    void helper(vector<int>& curr,int index,int n,vector<int>& nums){
        if(index == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]); //add the current element and call recusion 
        helper(curr,index+1,n,nums); //{{1,2,3}}
        curr.pop_back();        // remove the current element and call recursion
        helper(curr,index+1,n,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr;
        helper(curr,0,n,nums);
        return ans;
        
    }
};
