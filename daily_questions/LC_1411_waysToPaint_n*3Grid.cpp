#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9+7;

        long long samePattern = 6; //  ABA TYPE
        long long diffPattern = 6; //  ABC TYPE


        for(int r = 2; r<= n; r++){
            long long newSame = (samePattern*3 + diffPattern*2)%mod;
            long long newDiff = (samePattern*2 + diffPattern*2)%mod;

            samePattern = newSame;
            diffPattern = newDiff;
        }

        return (samePattern + diffPattern)%mod;
    }
};