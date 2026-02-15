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

    void solve(int idx,int n,int k,vector<int>& temp){
      
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(idx > n) return; // if curr element to explore is greater than n return
        temp.push_back(idx); //take the element and explore
        solve(idx+1,n,k-1,temp); // explore
        temp.pop_back(); //remove the element
        solve(idx+1,n,k,temp); // explore by skipping the element
        

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1,n,k,temp);

        return ans;
    }
};