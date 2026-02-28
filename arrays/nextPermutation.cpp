#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int vic = -1;

        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                vic = i-1;
                break;
            }
        }

        if(vic != -1){
            int swap_ind = -1;

            for(int i=n-1;i>=vic;i--){
                if(nums[i] > nums[vic]){
                    swap_ind = i;
                    break;
                }
            }
            swap(nums[vic],nums[swap_ind]);
        }

        reverse(nums.begin()+vic+1 , nums.end());
    }
};