#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int total_days(vector<int>& weights,int mid){
        int total =1;
        int tot_weight=0;
        for(int i=0;i<weights.size();i++){
            if(tot_weight+weights[i] <= mid){
                tot_weight+=weights[i];
            }
            else{
                tot_weight=0;
                total++;
                tot_weight+=weights[i];
            }
        }
        return total;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        
        while(low <= high){
            int mid = (low+high)/2;
            int tot_days = total_days(weights,mid);

            if(tot_days <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return low;
    }
};