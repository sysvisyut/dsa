#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    long long MOD = 1e9+7;
    long long power(long long base,long long exp){
        if(exp == 0) return 1;
        long long half = power(base,exp/2);     //3^6 = 3^3 * 3^3
        half = (half*half)%MOD;

        if(exp%2 == 0) return half;     
        else{
            return (base*half)%MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;

        return (power(5,even)*power(4,odd))%MOD;
    }
};