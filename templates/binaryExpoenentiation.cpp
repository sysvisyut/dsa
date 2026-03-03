#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

long long power(long long base, long long exp) {
    // 1. Base Case: Anything to the power of 0 is 1.
    int MOD = 1e9+7;
    if(exp == 0) return 1;

    // 2. Recursive Step: Find the result for HALF of the exponent.
    // If exp is 10, this finds base^5.
    long long half = power(base, exp/2);

    // 3. Square it: (base^(exp/2)) * (base^(exp/2))
    // We apply % MOD here to keep the number from becoming too huge.
    half = (half * half) % MOD;

    // 4. Handle Odd Exponents:
    if(exp % 2 == 0) {
        // If even (e.g., 10), we already have the full answer in 'half'.
        return half;
    } else {
        // If odd (e.g., 11), the integer division 'exp/2' dropped a 'base'.
        // We multiply it back in here.
        return (base * half) % MOD;
    }
}