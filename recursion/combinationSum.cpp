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
    void solve(vector<int>& curr,vector<int>& candidates,int sum,int index,int target){
        int n = candidates.size();
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(sum > target || index == n){ //base case for invalid cases to return early and stop infinite loop
            return;
        }
   
        curr.push_back(candidates[index]);
        solve(curr,candidates,sum+candidates[index],index,target); //take the current element and stay in the same index
        curr.pop_back();
        solve(curr,candidates,sum,index+1,target); //skip and move to the next index
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(curr,candidates,0,0,target);
        return ans;

    }
};