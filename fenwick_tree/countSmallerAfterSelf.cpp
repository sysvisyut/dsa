#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bit;

    void update(int i, int n){

        while(i < n){
            bit[i]+=1;
            i+=(i & -i);
        }
    }

    int sum(int i){
        int ans = 0;

        while(i > 0){
            ans+=bit[i];
            i-=(i & -i);
        }

        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);
        
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());

        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        bit.assign(temp.size()+1,0);

        for(int i=n-1;i>=0;i--){
            int rank = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin() + 1;

            ans[i] = sum(rank-1);

            update(rank,temp.size());
        }

        return ans;
    }
};