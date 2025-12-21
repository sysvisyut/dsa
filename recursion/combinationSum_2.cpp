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
    void helper(int index,int target,vector<int> curr, vector<int>& candidates){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=index;i<candidates.size();i++){ //everytime this loop runs it fills all elements at each place
            if(i>index && candidates[i-1]==candidates[i]) continue; //this checks if the curr element in the loop is same as the already filled element if yes then skip this element

            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            helper(i+1,target-candidates[i],curr,candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        helper(0,target,curr,candidates);
        return ans;
    }
};