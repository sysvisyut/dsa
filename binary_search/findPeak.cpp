#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() ==1) return 0;
        if(nums[0] > nums[1]) return 0;
        else if(nums[n-1] > nums[n-2]) return n-1;  // first and last element check individually.

        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

            else if(nums[mid] < nums[mid+1]){
                low = mid+1;                    //somewhere before the local peak, move towards the peak
            }
            else if(nums[mid-1] > nums[mid]){
                high = mid-1;               //somewhere after the peak,in the dip go behind to find the peak
            }
        }
        return -1;
    }
};