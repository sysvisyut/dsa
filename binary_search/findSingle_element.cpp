#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(nums[0]!=nums[1]) return nums[0];   //handle edge cases seperately
        else if (nums[n-1]!= nums[n-2]) return nums[n-1];
        else{
            int low = 1;
            int high = n-2;
            while(low <= high){
                int mid = (low+high)/2;
                if(nums[mid]!= nums[mid-1] && nums[mid] != nums[mid+1]){
                    return nums[mid];
                }
                else if(mid%2 == 0 && nums[mid+1] == nums[mid] || mid%2==1 && nums[mid-1] == nums[mid]){
                    low = mid+1;   // if the single element is on the right then eve,odd,even,odd...
                }
                else{
                    high = mid-1; // if the single element is on the left then odd,even,odd,even...
                }
            }
        }
        return -1;
    }
};