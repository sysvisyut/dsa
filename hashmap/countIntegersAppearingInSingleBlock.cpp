#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {


        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i == 0 || nums[i]!=nums[i-1]){
                mp[nums[i]]++;
            }
        }

        int cnt = 0;

        for(auto it: mp){
            if(it.second == 1){
                cnt++;
            }
        }
        return cnt;
    }
};