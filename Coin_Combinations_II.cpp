#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
 
const int mod = 1e9+7;
 

int main(){
    int n, x;
    cin>>n>> x;

    vector<int> coins(n);

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<vector<int>> dp(n+1, vector<int>( x+1, 0));

    // dp[i][j] -> sum j that is formed using coins (i to n-1)
    
    //base case: The sum 0 can be achieved always using 0 coins so dp[i][0] = 1

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    /* transition: at every state to maintain the ordered coin picking, 
    i make sure that all the coins are picked up in exact order, so that i dont reuse the coin
    which makes sure that 1+2+3 and 2+1+3 doesnt counted as seperate */

    for(int i=n-1;i >=0;i--){
        for(int j=1;j<=x;j++){
            int skip = dp[i+1][j];
            int take = 0;

            if(coins[i] <= j){
                take = dp[i][j-coins[i]];
            }
            dp[i][j] = (take+skip)%mod;
        }
    }

    cout<<dp[0][x];
}