#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pre = 1, suff = 1;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){

            if(pre==0) pre =1;
            if(suff==0) suff =1;

            pre*=nums[i];
            suff*=nums[n-i-1];

            maxi = max(maxi,max(pre,suff));
        }

        return maxi;
    }
};