#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        int n = nums.size();

        bool frst = 1;

        int ans = -1;

        for(int i=0;i<n;i++){
            if(nums[i] != i && frst){
                ans = nums[i];
                frst = false;
            }
            else if(nums[i] != i && frst == false){
                ans&=nums[i];
            }
        }

        return ans == -1 ? 0 : ans;


    }
};