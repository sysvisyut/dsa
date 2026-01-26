#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        int min_diff = INT_MAX;

        for(int i=0;i<n-1;i++){
            min_diff = min(min_diff,arr[i+1]-arr[i]);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i] == min_diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;

    }
};