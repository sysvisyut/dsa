#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;

            if(nums[low]==nums[mid] && nums[high]== nums[mid]){
                low++;
                high--;                    // we eliminate the case which causes problem
                continue;
            }

            if(nums[low] <= nums[mid]){     // left is sorted
                if(nums[low] <=target && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{                           // right is sorted
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};