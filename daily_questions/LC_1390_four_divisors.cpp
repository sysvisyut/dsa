#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
     
        int div_count =0;
        int ans=0;

        for( auto n : nums){
            int temp=0;
            int sum=0;
            for(int i=1;i*i<=n;i++){ //run loop till sqrt(n), after this divisors pair starts to repeat
                if(n%i == 0){
                    int d1 = i;
                    int d2 = n/i;
                    if(d1 == d2){
                        temp++;
                        sum+=d1;
                    }
                    else{
                        temp+=2;
                        sum += d1+d2;
                    }
                }
                if(temp > 4) break;
            }
            if(temp==4){
                ans+=sum;
            }
        }
        return ans;
        
    }
};