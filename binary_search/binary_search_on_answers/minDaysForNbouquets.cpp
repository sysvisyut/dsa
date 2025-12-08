#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cal_flowers(int mid, vector<int>& bloomDay, int k){
        int n = bloomDay.size();
        int bouquet =0;
        int avai=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){
                avai++;
                if(avai == k){
                    bouquet++;
                    avai = 0;
                }
            }
            else{
                avai=0;
            }
            
        }
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m || bloomDay.size() < k || bloomDay.size() < m*k) return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low <= high){
            int mid = (low+high)/2;
            int avai_bouquet = cal_flowers(mid,bloomDay,k);
            if(avai_bouquet >= m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};