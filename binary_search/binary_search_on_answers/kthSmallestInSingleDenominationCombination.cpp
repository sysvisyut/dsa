#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    typedef long long ll;

    ll gcd(ll a, ll b){
        if(b == 0) return a;

        return gcd(b,a%b);
    }

    ll countSmaller(ll mid, vector<int>& coins) { 
        ll correctedCount = 0;

        int n = coins.size();

      
        for(int terms = 1; terms <= (1 << n)-1; terms++) { //2^n-1 terms
            ll lcm = 0;
            ll order = 0; //even or odd order of terms

            for(int i = 0; i < n; i++) {
                if(terms & (1<<i)) {
                    order++; //we have taken ith coin

                    if(lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if(order % 2 == 0) { //even then subtract
                correctedCount -= mid/lcm;
            } 
            else {  //odd then add
                correctedCount += mid/lcm;
            }
        }

        return correctedCount;
    }

    ll findKthSmallest(vector<int>& coins, int k) {
        ll res= -1;

        ll l = 1;
        ll r = (ll)(*max_element(coins.begin(), coins.end()))*k;

        
        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(countSmaller(mid, coins) >= k) { //left side me we can find kth smallest element
                res = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
    }
};
