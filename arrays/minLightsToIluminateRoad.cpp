#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n,0);

        for(int i=0;i<n;i++){
            int v = lights[i];
            if(v> 0){
                int l = max(0,i-v);
                int r = i+v+1;
                diff[l]++;
                if(r<n)diff[r]--;
            }
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        int ans = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(diff[i] == 0){
                cnt++;
            }
            else{
                ans+= (cnt+2)/3;  //ceil division
                cnt = 0;
            }
        }
        ans+=(cnt+2)/3; //remaining unlighted region

        return ans;
    }
};