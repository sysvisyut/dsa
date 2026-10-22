#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return 0;

        int inv = 0;
        int zpos = -1;
        int lpos = -1;

        for(int i=1;i<n;i++){

            if(abs(nums[i]-nums[i-1]) > 1){
                inv++;
            }
            if(nums[i] == 0){
                zpos = i;
            }
            if(nums[i] == n-1){
                lpos = i;
            }

        }

        if(nums[0] == 0) zpos = 0;
        if(nums[0] == n-1) lpos = 0;

        if(abs(nums[n-1]-nums[0]) > 1) inv++;

        if(inv > 1) return -1;


        if((zpos-1+n)%n != lpos){

            return 1+min(lpos, n-zpos-1);
        }

        return min(zpos, n - lpos + 1);

    }
};