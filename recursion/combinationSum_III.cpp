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
    void helper(vector<int> curr,int sum,int index,int n,int k){
        if(sum == n && curr.size() == k){
            ans.push_back(curr);
            return;             
        }
        for(int i=index;i<=9;i++){
            curr.push_back(i);
            helper(curr,sum+i,i+1,n,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        helper(curr,0,1,n,k);
        return ans;
    }
};