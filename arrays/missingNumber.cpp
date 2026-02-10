#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for(int i=0;i<n;i++){
            xr^=i;
            xr^=nums[i];
        }
        xr^=n; // include the last element that got missed in the loop

        return xr;

    }
};

// [3,0,1]^[0,1,2,3] = 2 because elements cancels out