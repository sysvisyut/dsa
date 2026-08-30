#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int n = s.size();
        int r = 0;
        int l = 0;
        if(n == 0) return 0;
        int maxLen = 0;

        while(r<n){
            if(hash[s[r]] >= l){ //duplicate char exists inside the curr window
                l = hash[s[r]]+1;
            }
          
            hash[s[r]] = r;
        

            maxLen = max(maxLen,r-l+1);
            r++;

        }
        return maxLen;
    }
};