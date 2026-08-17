#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        if(n == 1) return 0;

        vector<int> left(n), right(n);


        //find the earliest possible matching letter
        int j = 0;
        for(int i=0;i<n;i++){
            while(station[j] != skill[i]){
                j++;
            }
            left[i] = j;
            j++;
        }
        
        // find the last possible matching letter
        j= m-1;

        for(int i=n-1;i>=0;i--){
            while(station[j] != skill[i]){
                j--;
            }
            right[i] = j;
            j--;
        }

        int ans = INT_MIN;


        for(int i=1;i<n;i++){
            ans = max(ans,right[i]-left[i-1]);
        }
        return ans;
        
    }
};