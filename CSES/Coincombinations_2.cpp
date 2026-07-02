#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
 
const int mod = 1e9+7;
 
int main(){
    int n,x;
 
    cin>>n>>x;
 
    vector<int> coins(n);
 
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
 
    sort(coins.begin(),coins.end());
 
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
 
    for(int i=0;i<n+1;i++){
        dp[i][x] = 1;
    }
 
    for(int sum=x-1; sum>=0;sum--){
        for(int i = n-1;i>=0;i--){
            long long ans = 0;
            for(int j = i;j<coins.size();j++){
                if(sum+coins[j] <= x){
                    ans = (ans+dp[j][sum+coins[j]])%mod;
                }
            }
 
            dp[i][sum]= ans;
        } 
    }
 
 
 
    cout<<dp[0][0];
 
}