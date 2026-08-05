#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int> mp;

        for(auto it: edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }

        for(auto it: mp){
            if(it.second == n){
                return it.first;
            }
        }

        return -1;
    }
};