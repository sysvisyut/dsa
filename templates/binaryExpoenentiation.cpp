#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int mod = 1e9+7;

long long f(long long base,long long exp){
    long long ans = 1;
    base%=mod;

    while(exp > 0){
        if(exp&1){
            ans = (ans*base)%mod;
        }
        base = (base*base)%mod;
        exp>>=1;
    }

    return ans;

}
int main() {
    
    long long x,y;
    cin>>x>>y;

    long long res = f(x,y);

    cout<<res;

    return 0;
}