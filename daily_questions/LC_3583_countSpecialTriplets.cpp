#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int m = 1e9+7;
        unordered_map<int,int> prev;
        unordered_map<int,int> next;
        int ans =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            next[nums[i]]++;           //initially store all the elements in the next array for reference
        }
        for(auto &it: nums){
            next[it]--;             //when we reach the particular element remove it from the next map

            int left = prev[it*2]; //check in the prev map if the required element exists
            int right = next[it*2];//check in the next map if the required element exists

            ans = (ans+(1LL*left*right))%m; // increase the ans by the total combinations of prev and next
            prev[it]++; //include the particular element in the prev map for the use of future elements
        }

        return ans;
    }
};