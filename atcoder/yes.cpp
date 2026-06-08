#include <cmath>

int countPerfectPowers(int l, int r, int k) {
    
    if (k == 1) return r - l + 1;

    int a = pow(r, 1.0 / k),b = l ? pow(l - 1, 1.0 / k):-1;

    int a=pow(r, 1.0 / k);

    if (l != 0){
        b = pow(l - 1, 1.0 / k);

    } else {
        b = -1;

    }

    while (pow(a + 1, k) <= r) a++;
    while (l && pow(b + 1, k) < l) b++;
    return a - b;
}