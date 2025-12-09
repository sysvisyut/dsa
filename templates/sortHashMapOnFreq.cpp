#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it : nums){
            mp[it]++;
        }
        vector<pair<int,int>>v(mp.begin(),mp.end());
        
        sort(v.begin(),v.end(),[](const pair<int,int>&a, const pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;   //if freq equal sort by value in desc
            }
            return a.second < b.second; // else sort them by freq in asc
        });

        vector<int> ans;
        ans.reserve(nums.size());   // use reserve to preallocate space in vector
        for(auto &p : v){
            ans.insert(ans.end(),p.second,p.first); // insert into ans(start pos, count, val)
        }
        return ans;

    }
};