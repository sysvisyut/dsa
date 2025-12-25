#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum = happiness[0];
        if(k == 1) return sum;
        int minus = 1;
        for(int i=1;i<k;i++){
            long long dec = happiness[i]-minus;
            if(dec <0){
                sum+=0;
            }
            else{
                sum+=dec;
                minus++;
            }
        }
        return sum;
    }
};