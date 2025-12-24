#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        //sort(apples.begin(),apples.end());
        int n = capacity.size();
        int tot_apples = accumulate(apple.begin(),apple.end(),0);
        int ans = 0;
        int cap = 0;

        for(int i=0;i<n;i++){
            if(tot_apples > cap){
                cap+=capacity[i];
                ans++;
            }
            else{
                return ans;
                break;
            }
        }
        return ans;
    }
};