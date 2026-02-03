#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i+1 < n && nums[i+1]>nums[i]){
            i++;
        }
        int temp =i;
        if(i==0 || i== n-1) return false;
        while(i+1<n && nums[i+1]<nums[i]){
            i++;
        }
        if(i==temp || i==n-1) return false;

        while(i+1<n && nums[i+1]>nums[i]){
            i++;
        }
        if(i== n-1) return true;

        return false;
    }
};