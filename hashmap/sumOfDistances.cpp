#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
typedef long long ll;
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> res(n);

        unordered_map<ll,vector<int>> mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        for(auto& it: mp){
            vector<int>& nums = it.second;
            int sz = nums.size();

            vector<ll> prefix(sz,0);
            prefix[0] = nums[0];

            for(int i=1;i<sz;i++){
                prefix[i] = prefix[i-1]+nums[i];
            }

            for(int i=0;i<sz;i++){
                ll left =0, right = 0;
                ll curr = nums[i];

                if( i > 0){
                    left = (ll)i*nums[i] - prefix[i-1];
                }
                if( i < sz-1){
                    right = (prefix[sz-1]-prefix[i]) - (ll)(sz-i-1)*nums[i];
                }

                res[curr] = left + right;
            }

        }

        return res;
    }
};