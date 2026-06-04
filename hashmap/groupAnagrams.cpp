#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(string &w : strs){
            string temp = w;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(w);
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};