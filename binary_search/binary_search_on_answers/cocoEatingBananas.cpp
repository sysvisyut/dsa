#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long tot_hours(int mid,vector<int>& piles){
        int n = piles.size();
        long long hours =0;
        for(int i=0;i<n;i++){
            hours+= (piles[i]+mid-1)/mid;     
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;

        while(low <= high){
            int mid = (low+high)/2;
            long long hrs = tot_hours(mid,piles);
            if(hrs <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};