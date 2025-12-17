#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    double helper(double x,long long n){
        if(n==0) return 1;
        double half = myPow(x,n/2);
        half*=half;
        if(n%2 == 0){
            return half;
        }
        else{
            return x*half;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
        return helper(x,N);
    }
};