#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int ans = 0;

        if(cost.size()< 3){
            int sum = accumulate(cost.begin(),cost.end(),0);
            return sum;
        }
        int cnt = 0;

        for(int i=n-1;i>=0;i--){
            cnt++;
            if(cnt >= 3){
                cnt = 0;
                continue;
            }
            ans+=cost[i];

        }

        return ans;
    }
};