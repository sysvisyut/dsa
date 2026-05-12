#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
  public:
  
    vector<int> sieve(int n) {
        // code here
        vector<bool> p(n+1,true); //mark all numbers as prime
        p[0] = 0;
        p[1] = 0;
        
        for(int i=2;i*i <= n;i++){ // start from 2 and go till sqrt(n) to find all factor pairs
            if(p[i]){
                for(int j=2;i*j <= n; j++){ //mark the multiples of prime as false
                    p[i*j] = 0;
                }
            }
        }
        vector<int> ans;
        
        for(int i=2;i<=n;i++){
            if(p[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};