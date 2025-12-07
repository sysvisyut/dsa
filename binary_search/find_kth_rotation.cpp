#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//logic find min in a sorted roated array using binary search and keep track of the index of the min element
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low =0;
        int high = arr.size()-1;
        int ans = INT_MAX;
        int ans_ind =0;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[low] <= arr[mid]){
                if(ans > arr[low]){    
                    ans = arr[low];
                    ans_ind = low;
                }
                low = mid+1;
            }
            else{
                if(ans > arr[mid]){
                    ans = arr[mid];
                    ans_ind = mid;
                }
                high = mid-1;
                
            }
        }
        return ans_ind;
    }
};
