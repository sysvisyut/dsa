#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();   
        int penality = 0;

        for(int i=0;i<n;i++){
            if(customers[i] == 'Y') penality++;
        }
        int min_penality = penality;
        int min_time = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                penality--;
            }
            else{
                penality++;
            }
            if(penality < min_penality){
                min_penality = penality;
                min_time = i+1; // time after you serve the current customer
            }
        }
        return min_time;
    }
};