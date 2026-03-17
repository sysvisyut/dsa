#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();

        vector<int> r(n,2),l(n,2);

        for(int i=2; i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                l[i] = l[i-1]+1;
            }
        }

        for(int i=n-3; i>=0;i--){
            if(nums[i]-nums[i+1] == nums[i+1]-nums[i+2]){
                r[i] = r[i+1]+1;
            }
        }
        int maxLen = 2;
        for(int i=0;i<n;i++){
            if(i >0){
                maxLen = max(maxLen,l[i-1]+1);
            }
            if(i< n-1){
                maxLen = max(maxLen,r[i+1]+1);
            }

            if(i>0 && i <n-1){
                if((nums[i+1]+nums[i-1])%2 ==0){

                    int d = (nums[i+1]-nums[i-1])/2;

                    int len_l =1,len_r = 1;

                    if(i>=2 && nums[i-1]-nums[i-2] == d){
                        len_l = l[i-1];
                    }
                    if(i <= n-3 && nums[i+2]-nums[i+1] == d){
                        len_r = r[i+1];
                    }

                    maxLen = max(maxLen, len_l + len_r +1);
                }
            }
        }

        return maxLen;

        
        
    }
};