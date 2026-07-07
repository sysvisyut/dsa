#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        /* [[2,3],[1,4],[3,4]]
        [[3,5],[0,6],[4,7][1,7]]*/
        auto lambda = [](auto &a, auto& b){
            if(a[1] == b[1]){
                return a[0] > b[0];
            }

            return a[1] < b[1];
        };   

        sort(intervals.begin(),intervals.end(),lambda);
        int n = intervals.size();

        // int prevEnd = intervals[n-1][1];
        int prevSt = intervals[n-1][0];

        int cnt = 0;

        for(int i=n-2;i>=0;i--){
            if(intervals[i][0] >= prevSt){
                cnt++;
            }
            else{
                prevSt = intervals[i][0];
            }
        }

        return n-cnt;
        
    }
};