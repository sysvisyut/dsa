#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& in, int fs, int fe) {

        /*first task is to merge overlapping intervals
        */


        sort(in.begin(), in.end()); //sort based on the start times

        vector<vector<int>> merged;

        int n = in.size();

        auto prev = in[0];

        for(int i=1;i<n;i++){
            if(in[i][0] <= prev[1]+1){
                prev[1] = max(prev[1], in[i][1]);
            }
            else{
                merged.push_back(prev);
                prev = in[i];
            }
        }
        merged.push_back(prev);

        vector<vector<int>> ans;

        for(auto it: merged){
            int st = it[0], end = it[1];

            if(end < fs || st > fe){
                ans.push_back({st,end});
                continue;
            }
            
            if(st < fs){
                ans.push_back({st, fs-1});
            }
            if(end > fe){
                ans.push_back({fe+1,end});
            }
        }

        return ans;
        

    }
};