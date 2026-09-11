#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int helper(int num){
        int ones = 0;
        while(num > 0){
            if(num&1) ones++;
            num>>=1;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        
        vector<int> ans;

        for(int i=0;i<=n;i++){
            int cnt = helper(i);
            ans.push_back(cnt);
        }

        return ans;
    }
};