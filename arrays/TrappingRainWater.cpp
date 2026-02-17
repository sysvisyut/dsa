#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int curMax = height[0];
        vector<pair<int,int>> ans(n);
        ans[0].first = 0;
        
        for(int i=1;i<n;i++){
            if(curMax < height[i]){
                ans[i].first =0;
            }
            else ans[i].first = curMax;
            curMax = max(curMax, height[i]);
        }
    
        curMax  = height[n-1];
        ans[n-1].second = 0;
        for(int i=n-2;i>=0;i--){
            if(curMax < height[i]){
                ans[i].second = 0;
            }
            else ans[i].second = curMax;
            curMax = max(curMax,height[i]); 
        }
        int cap =0;
        for(int i=0;i<n;i++){
            if(ans[i].first == 0 || ans[i].second == 0) continue;

            cap += min(ans[i].first , ans[i].second)-height[i];
        }

        return cap;
    
    }
};

