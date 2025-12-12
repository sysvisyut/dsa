#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k,int mid){
        int cows =1;
        int temp =stalls[0];
        for(int i=1;i<stalls.size();i++){
            if((stalls[i]- temp) >= mid){
                cows++;
                temp = stalls[i];
            }
        }
        if(cows >= k) return true;
        else return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        while(low <= high){
            int mid = (low+high)/2;
            if(isPossible(stalls,k,mid)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};