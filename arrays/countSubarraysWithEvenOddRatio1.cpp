#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<int> cont(n);

        for(int i=0;i<n;i++){
            if(nums[i]&1){
                cont[i] = -a;
            }else{
                cont[i] = b;
            }
        }

        vector<int> prefix(n,0);
        prefix[0] = cont[0];

        for(int i=1;i<n;i++){
            prefix[i] = cont[i]+prefix[i-1];
        }
        int ans = 0;

        for(int r=0;r<n;r++){
            for(int l=0;l<=r;l++){
                int sum = (l == 0 ? prefix[r] :prefix[r]-prefix[l-1]);
                if(sum <= 0){
                    ans++;
                }
            }
        }

        return ans;

    }
};